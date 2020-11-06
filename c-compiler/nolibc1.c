//typedef long ssize_t;
//typedef unsigned long size_t;
//ssize_t write(int fd, const void *buf, size_t count);
int main(int argc, char* argv[]){
	//write(1, "hello world\n", 12);
	char *addr = "hello world\n";
	int len = 12;
	register long r_syscallno asm("rax") = 1;
	register long r_arg1 asm("rdi") = 1;
	register long r_arg2 asm("rsi") = (long) addr;
	register long r_arg3 asm("rdx") = len;
	register long retvalue asm("rax");
	asm("syscall");

	return retvalue;
}
