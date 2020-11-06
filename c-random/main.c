#include <stdio.h>
#include "static.h"	//inclusione dei file nella stessa directory
#define STAMPA(X) printf("var:" #X " %d\n", X)
#define STAMPAF(F,X) F ## f("var:" #X " %d\n", X)

int i;
int main(){
	printf("%d\n", b());
	printf("%d\n", b());
	printf("%d\n", b());
	printf("%d\n", i);
#ifdef DEBUG
	printf("debug\n");
#endif
	STAMPA(i);
	STAMPAF(print, i);
	return 0;
}
