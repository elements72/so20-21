#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdint.h>
#include <fcntl.h>

void error(char *s){
	perror(s);
	exit(1);
}
#define CPUBUFSIZE 128
uint8_t buf[CPUBUFSIZE];
int main(int argc, char* argv[]){
	int fdin, fdout;
	ssize_t len;
	fdin = open(argv[1], O_RDONLY);
	if(fdin == -1)
		error("open in");
	fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fdout == -1)
		error("open out");
	while((len = read(fdin, buf, CPUBUFSIZE))>0)
		write(fdout, buf, len);
	close(fdin);
	close(fdout);
}

