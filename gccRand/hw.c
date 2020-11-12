//#include <stdio.h> //se commentiamo il compilatore ci da un warning in quanto
//		     non può controllare il valore passato alla funzione
int printf(const char *format, ...);	//Scriviamo la signature della printf

int main(int argc, char* argv[]){
	printf("Hello world %d", 42);
}
