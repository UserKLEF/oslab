#include <fcntl.h>
#include <unistd.h> /* For STDOUT_FILENO */
#include <stdio.h>
int main(int argc, char **argv) {
int size, fd;
char buf; /* Single-character buffer */
char *mesg = "Single filename required\n";
if ((fd = open(argv[1], O_RDONLY)) == -1)
perror("open");
lseek(fd, 1, SEEK_END); /* Pointer taken to EOF + 1 first */
while (lseek(fd, -2, SEEK_CUR) >= 0) { /* and then back by two bytes */
if (read(fd, &buf, 1) != 1)
perror("read");
if (write(STDOUT_FILENO, &buf, 1) != 1)
perror("write");
}
close(fd); /* Can have error here too */
exit(0); /* exit doesn't return - hence 
}
