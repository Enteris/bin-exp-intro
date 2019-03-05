#include <stdio.h>

/*
compiled with :
gcc -m32 -O0 -ggdb3 -fno-stack-protector -masm=intel \
-no-pie -mpreferred-stack-boundary=2 -o level3 level3.c
run this command to deactivate ASLR for this session : 
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
*/

const char path[] = "/bin/sh";

int here_is_some_code()
{

    __asm__("int 0x80");
    
    __asm__("xor eax, eax");
    __asm__("push eax");
    __asm__("pop edx");
    __asm__("ret");
    
    __asm__("mov eax, 0xb");
    __asm__("ret");

    __asm__("pop ecx");
    __asm__("ret");
    
    __asm__("pop ebx");
    __asm__("ret");
}

int main()
{
    char name[20];

    printf("Welcome to the third level of binary exploitation workshop!\n");
    printf("Putting code on the stack was too easy. That won't work this time!\n");
    fgets(name, 3000, stdin);

    printf("You entered : %s\n", name);

    //this_is_a_win_function();

    return 0;
}

