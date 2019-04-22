#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include<wait.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
    if(argc > 1 ){
    if(fork()==0){
     int fd = open("Lab3.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
     dup2(fd,1);
     execvp(argv[1], &argv[1]); //ls
     perror("exec error");
     exit(2);
    }
    else{
     int rv;
     wait(&rv);
     printf("Exit status: %d\n", WEXITSTATUS(rv));
             exit(0);
     }
 }
 else{
    perror("Error Provide arguments\n");
 }
}   

