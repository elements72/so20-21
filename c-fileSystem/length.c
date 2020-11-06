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
	struct stat buf;
	int rv = stat(argv[1], &buf);
	if(rv == -1)
		error("stat");
	printf("%ld\n", buf.st_size);
	return 0;
}
