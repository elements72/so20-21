#include <stdio.h>
int main(){
	char *s ="ciao";
	*(++s)='a';
	printf(s);
}
