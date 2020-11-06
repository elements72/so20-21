#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
//Test per creare processo zombie

int main(int argc, char *argv[])
{
    pid_t pid;
    if ((pid = fork()) != 0){
        int status;
        printf("genitore %d %d %d\n", pid, getpid(), getppid());
        sleep(20);	//Facciamo terminare prima il processo figlio
	waitpid(pid, &status, 0);
        printf("status %d %x\n", status, status);
        _exit(0);
    }
    else
    {
        printf("figlio %d %d %d\n", pid, getpid(), getppid());
        _exit(44);
    }
}
