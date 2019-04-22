#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h> 
#include <time.h> 
 
int main(void) 
{ 
    int f_d = 0; 
    struct stat st; 
    f_d = open("test.txt",O_RDONLY); 
 
    //Check if open() was successful 
    if(-1 == f_d) 
    { 
        printf("\n NULL File descriptor\n"); 
        return -1; 
    } 
    errno = 0; 
    // Now a call to fstat is made 
    // Note that the address of struct stat object 
    // is passed as the second argument 
    if(fstat(f_d, &st)) 
    { 
        printf("\nfstat error: [%s]\n",strerror(errno)); 
        close(f_d); 
        return -1; 
    } 
    switch (st.st_mode & S_IFMT) { 
           case S_IFBLK:  printf("block device\n");            break; 
           case S_IFCHR:  printf("character device\n");        break; 
           case S_IFDIR:  printf("directory\n");               break; 
           case S_IFIFO:  printf("FIFO/pipe\n");               break; 
           case S_IFLNK:  printf("symlink\n");                 break; 
           case S_IFREG:  printf("regular file\n");            break; 
           case S_IFSOCK: printf("socket\n");                  break; 
           default:       printf("unknown?\n");                break; 
           } 
     printf("File size:                %lld bytes\n",(long long) st.st_size); 
     printf("Last status change:       %s", ctime(&st.st_ctime)); 
     printf("Last file access:         %s", ctime(&st.st_atime)); 
     printf("Last file modification:   %s", ctime(&st.st_mtime));
    close(f_d); 
    return 0; 
}

