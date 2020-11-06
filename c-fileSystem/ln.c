#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void error(char *s){
	perror(s);
	return;
}

int main(int argc, char* argv[]){
	int rv = link(argv[1], argv[2]);
	if(rv == -1)
		error("link");
}
