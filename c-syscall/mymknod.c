#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>

int main(int argc, char *argv[]) {
	dev_t devno = makedev(atoi(argv[2]), atoi(argv[3]));
	mknod(argv[1], S_IFCHR | 0777, devno);
	chmod(argv[1], 0666);
}
