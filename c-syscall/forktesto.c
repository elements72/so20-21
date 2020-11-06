#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
//Test per creare un processo orfano

int main(int argc, char *argv[])
{
    pid_t pid;
    if ((pid = fork()) != 0){
        int status;
        printf("genitore %d %d %d\n", pid, getpid(), getppid());
	//waitpid(pid, &status, 0);
        //printf("status %d %x\n", status, status);
        _exit(0);
    }
    else
    {
	sleep(10);
        printf("figlio %d %d %d\n", pid, getpid(), getppid());
        _exit(44);
    }
}
