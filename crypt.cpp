#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
int main(){
    char buf;
    int c;
    int  fd1 = open("/etc/passwd", O_RDONLY);
    int  fd2 = open("crypt.txt", O_CREAT | O_WRONLY |O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP |S_IROTH);
    while(1){
      if(read(fd1,&buf,1)!=0)
        write(fd2,&buf,1);
      else
        break;
    }
    close(fd1);
    close(fd2);


    fd1 = open("crypt.txt",O_RDONLY);
    fd2 = open("decrypt.txt",O_CREAT | O_WRONLY |O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP |                S_IROTH);
    lseek(fd1,-2,SEEK_END);
    read(fd1,&buf,1);
    printf("%c",buf);
    while(buf != '\n'){
      lseek(fd1,-2,SEEK_CUR);
      read(fd1,&buf,1);
    }
    //saving the 12 characters to decrypt.txt
    char s[12];
    read(fd1,s,12);
    write(fd2,s,12);
    close(fd1);
    close(fd2);


  fd1 = open("decrypt.txt", O_RDONLY);
    while(1){
      if(read(fd1,&buf,1)!=0)
        write(1,&buf,1);
      else
        break;
    }
    return 0;
}


