#include <stdio.h>

/*
compiled with :
gcc -m32 -O0 -ggdb3 -fno-stack-protector -z execstack \
-no-pie -mpreferred-stack-boundary=2 -o level2 level2.c
run this command to deactivate ASLR for this session : 
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
*/

int this_is_a_win_function()
{
    printf("Well, you learned how to jump somewhere last time...can you jump in the stack now?\n");

    //system("/bin/sh");
}

int main()
{
    char name[1000];

    printf("Welcome to the second level of binary exploitation workshop!\n");
    printf("You know the drill. Your buffer has the same length, but we'll read 3000 bytes this time.\n");
    fgets(name, 3000, stdin);

    printf("You entered : %s\n", name);

    //this_is_a_win_function();

    return 0;
}

