#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void error(char *s) {
	perror(s);
	exit(1);
}

int main(int argc, char *argv[]) {
	int fddir = openat(AT_FDCWD, argv[1], O_PATH);
	int fd = openat(fddir, argv[2], O_RDONLY);

	char buf[1024];
	ssize_t len;
	while ((len = read(fd, buf, 1024)) > 0)
		write(STDOUT_FILENO, buf, len);
}

