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
	int fdin, fdout;
	ssize_t len;
	struct stat sbuf;
	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
		error("open in");
	fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fdout == -1)
		error("open out");
	
	int rv = fstat(fdout, &sbuf);
	if (rv == -1)
		error("fstat");
	blksize_t blksize = sbuf.st_blksize;
	uint8_t buf[blksize];

	while ((len = read(fdin, buf, blksize)) > 0)
		write(fdout, buf, len);

	close(fdin);
	close(fdout);
}

