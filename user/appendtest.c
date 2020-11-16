#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main(void) {
    int fd1 = open("appendfile", O_WRONLY | O_CREATE | O_TRUNC);
    write(fd1, "Hello, World!\n", 14);
    close(fd1);

    int fd2 = open("appendfile", O_WRONLY | O_APPEND);
    write(fd2, "Append test\n", 12);
    close(fd2);

    exit(0);
}
