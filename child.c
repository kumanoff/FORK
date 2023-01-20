#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <locale.h>
#include <unistd.h>// for write and read 
int main(int argc, char* argv[]) {
    if (argc < 1) {
        printf("Использование: file text_file new_text_file \n");
        printf("get = %s\n", *argv);
        //printf("number = %d\n", argc);
        exit(-1);
    }
    setlocale(LC_ALL, "Rus");
    int inputFd, outputFd, numRead, total, openFlags;
    mode_t filePerms;
    // открытие файлов ввода и вывода
    inputFd = open(argv[0], O_RDONLY);
    if (inputFd == -1) {
        printf("Error opening file: %s!\n", argv[0]);
        exit(-2);
    }
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    char fname[]="out.txt";
    int i=1;
    outputFd = open(fname, O_RDONLY);
    printf("outputFd = %d \n", outputFd);
    while (outputFd >= 0 ){
        close(outputFd);
        sprintf(fname, "out%d.txt", i);
        i++;
        outputFd = open(fname, O_RDONLY);
        printf("outputFd_gygy = %d \n", outputFd);
    }
    close(outputFd);
    outputFd = open(fname, openFlags, filePerms);
    
    
     char buf;
     total = 0;
     // цикл для обработки файла
     while ((numRead = read(inputFd, &buf, 1) > 0))
        {
         write(outputFd, &buf, numRead);
         if (buf == '.') {
            buf = 0x0a;
            write(outputFd, &buf, numRead);
            total++;
         }
     }
     printf("Amount of operations: %d\n", total);
     close(inputFd);
     close(outputFd);
}
