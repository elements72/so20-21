#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	printf("%d %d\n", getuid(), geteuid());
	getchar();
}
