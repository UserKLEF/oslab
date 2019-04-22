#define _BSD_SOURCE
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
voidtypeOfFile(struct stat info){
if (S_ISDIR(info.st_mode)) {
printf("dir");
}
}
void main(intargc, char *argv[]) {
DIR *dirp;
structdirent* dent;
struct stat info;
typeOfFile(info);
if(argc == 1){
argv[1] = ".";
dirp=opendir(argv[1]); // specify directory here: "." is the "current directory"
do {
dent = readdir(dirp);
if (dent)
{
if (stat(argv[1], &info) == -1) {
perror("stat");
exit(EXIT_FAILURE);
}
switch (info.st_mode& S_IFMT) {
case S_IFDIR: printf("dir "); break;
default: printf("unknown?\n"); break;
}
printf("%s \n", dent->d_name);
}
while(dent);
closedir(dirp);
}
}
}

