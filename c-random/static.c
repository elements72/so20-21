#include <stdio.h>

void a(void){
	int i = 3;
}

int b(void){
	//int i commentare la linea successiva per verificare che a e b
	//occupano la stessa zona di memoria e che i conserva il valore
	//dichiarato in a();
	static int i;
	i++;
	return i;
}

