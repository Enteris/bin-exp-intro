#include <stdio.h>
#include <stdlib.h>

/*
compiled with :
gcc -m32 -O0 -ggdb3 -fno-stack-protector -z execstack 
-no-pie -mpreferred-stack-boundary=2 -o level1 level1.c
*/

int this_is_a_win_function()
{
    printf("Good job! You get a shell for your efforts!\n");

    system("/bin/sh");
}

int main()
{
    char name[20];

    printf("Welcome to the first level of binary exploitation workshop!\n");
    printf("What is your name :\n");
    fgets(name, 100, stdin); //Using fgets as gets was removed from C11

    printf("Welcome %s\n", name);

    //this_is_a_win_function();

    return 0;
}

