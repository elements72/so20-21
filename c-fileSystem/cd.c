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
	int rv = mkdir(argv[1], 0755);
	if(rv == -1)
		error("mkdir");
	rv = chdir(argv[1]);
	if(rv == -1)
		error("chdir");
	char *cwd = getcwd(NULL, 0);
	printf("%s\n", cwd); 
}
