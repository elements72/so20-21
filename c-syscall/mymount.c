#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/mount.h>

int main(int argc, char *argv[]) {
	mount(argv[1], argv[2], argv[3], 0, NULL);
}
