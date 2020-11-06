#include <stdio.h>

char *spoint = "hello";
char sarr[] = "hello";
struct strs
{
    char s[6];
} sstruct = {"hello"};

void foo(char *s)
{
    s[4] = 0;
}

void bar(struct strs s) //Le strutture sono passate per valore
{
    s.s[4] = 0;
    printf("from bar %s\n", s.s);
}

int main(int argc, char *argv[])
{
    printf("%s %s %s\n", spoint, sarr, sstruct.s);
    foo(sarr);
    printf("%s %s %s\n", spoint, sarr, sstruct.s);
    bar(sstruct);       
    printf("%s %s %s\n", spoint, sarr, sstruct.s);
    // test the following statements, one at a time
    //spoint = sarr;        Posso assegnare un array ad un puntatore ma non il contrario
    //sarr = spoint;
    foo(spoint);
    printf("%s %s %s\n", spoint, sarr, sstruct.s);
}