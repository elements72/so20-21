#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdint.h>
#include <sys/syscall.h>

void error(char *s){
	perror(s);
	exit(1);
}
struct linux_dirent {
	unsigned long  d_ino;     /* Inode number */
	unsigned long  d_off;     /* Offset to next linux_dirent */
        unsigned short d_reclen;  /* Length of this linux_dirent */
        char           d_name[];  /* Filename (null-terminated) */
                                 /* length is actually (d_reclen - 2 -
                                    offsetof(struct linux_dirent, d_name)) */
};
#define DIRBUFSIZE 4096

int main(int argc, char* argv[]){
	uint8_t buf[DIRBUFSIZE];
	int d = open(argv[1], O_DIRECTORY | O_RDONLY);
	int len;
	if(d == -1)
		error("open");
	while((len = syscall(__NR_getdents, d,(struct linux_dirent *)buf, DIRBUFSIZE))>0){
	uint8_t *scan = buf;
	while(scan < buf + len){
		struct linux_dirent *current = (struct linux_dirent *)scan;
		printf("%s %ld\n", current->d_name, current->d_ino);
		scan += current->d_reclen;
		}
	}
}

