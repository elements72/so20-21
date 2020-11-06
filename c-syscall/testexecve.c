#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char *newarg[] = {"showpid", NULL};
	printf("io sono testexecve %d\n", getpid()); 
       	execve("./showpid", newarg, NULL);
}
