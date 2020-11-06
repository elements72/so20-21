
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>
#include <fcntl.h>

void error(char *s){
	perror(s);
	exit(1);
}
int main(int argc, char* argv[]){
	int fdout;
	int status;
	fdout = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fdout == -1)
		error("open out");
	dup2(fdout, STDOUT_FILENO);
	switch(fork()){
		case 0:
			printf("Ciao\n");
			//write(fdout, "CIAO\n", 5);
			exit(0);
		default:
			printf("MARE\n");
			//write(fdout, "MARE\n", 5);
			wait(&status);
		case -1:
			exit(1);
	}
	close(fdout);
}

