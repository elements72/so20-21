#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

void error(char *s){
	perror(s);
	return;
}

int main(int argc, char* argv[]){
	struct dirent *de; 
	DIR *d = opendir(argv[1]);
	if(d == NULL)
		error("opendir");
	while((de  = readdir(d))!=NULL){
		printf("%s\n", de->d_name);
	}
}
