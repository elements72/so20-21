#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
        pid_t pid;
        if((pid = fork()) != 0){
                int status;
                printf("genitore %d %d %d\n", pid, getpid(), getppid());
                waitpid(pid, &status, 0);
                printf("exit status  %d\n", WEXITSTATUS(status));
                _exit(0);
        }
        else{
		int retval;
                printf("io sono proc figlio: %d\n", getpid());
                retval = execlp("lsx", "ls", "/", NULL);
		if(retval == -1){
			//printf("errno = %d", errno);
                        perror("programma");
		}
                _exit(-1);
        }
}
