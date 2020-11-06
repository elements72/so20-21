#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
	pid_t pid;
	if((pid = fork()) != 0){ //Evitiamo warning dal compilatore
		int status;
		printf("genitore %d %d %d\n",pid, getpid(), getppid());
		waitpid(pid, &status, 0);
		printf("status %d %x\n", status, status);
		_exit(0);
	}
	else{
		printf("figlio %d %d %d\n",pid, getpid(), getppid());
		sleep(1);
		_exit(44);
	}
}
