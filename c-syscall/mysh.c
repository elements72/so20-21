#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<execs.h>

int main(int argc, char *argv[]) {
	char *line = NULL;
	size_t linelen = 0;
	for(;;) {
		int status;
		pid_t pid;
		printf("prompt> ");
		fflush(stdout);
		if (getline(&line, &linelen, stdin) <= 0)
			break;
		switch (pid = fork()) {
			case 0:
				/* ridirezione */
				{
					char *gt;
					int f;
					if ((gt = strchr (line, '>')) != NULL) {
						*gt++ = 0;
						while (*gt == ' ') gt++;
						char *nl = strchr(line, '\n');
						if (nl != NULL) *nl = 0;
						f = open(gt, O_WRONLY | O_CREAT | O_TRUNC, 0777);
						if (f >= 0) {
							dup2(f, STDOUT_FILENO);
							close(f);
						}
					}
				}
				execsp(line);
				exit(255);
			default:
				waitpid(pid, &status, 0);
				break;
			case -1:
				break;
		}
	}
	if (line)
		free(line);
	return 0;
}
