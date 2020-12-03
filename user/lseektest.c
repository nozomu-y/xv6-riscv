#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main(void) {
    int fd = open("lseekfile", O_RDWR| O_CREATE | O_TRUNC);
    char buff[1024];
    int offset = lseek(fd, 0, SEEK_CUR);
    printf("offset: %d (0)\n", offset);
    write(fd, "test1\n", 6);
    
    offset = lseek(fd, 4, SEEK_SET);
    printf("offset: %d (4)\n", offset);
    write(fd, "test2", 5);

    offset = lseek(fd, 0, SEEK_CUR);
    printf("offset: %d (4-1+6=9)\n", offset);

    lseek(fd, 0, SEEK_SET);
    read(fd, buff, 1024);
    printf("%s\n", buff);

    offset = lseek(fd, 20, SEEK_END);
    printf("offset: %d (9+20=29)\n", offset);
    write(fd, "test3\n", 6);

    offset = lseek(fd, 0, SEEK_END);
    printf("offset: %d (29+6=35)\n", offset);

    close(fd);

    exit(0);
}
