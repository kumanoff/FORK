#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <locale.h>
#include <unistd.h>// for write and read 
int main(){
    char fname[]="food.txt";
    int i=1;
    int outputFd;
    outputFd = open(fname, O_RDONLY);
    while (outputFd > 0){
        close(outputFd);
        sprintf(fname, "food%d.txt", i);
        i++;
        printf("fname = %s\n", fname);
        outputFd = open(fname, O_RDONLY);
    }
    return 0;
}
