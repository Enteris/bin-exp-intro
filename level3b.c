#include <stdio.h>
#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <error.h>
#include <fenv.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <signal.h>
#include <stdalign.h>
#include <stdatomic.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//This way I won't need to include other stuff later!


/*
compiled with :
gcc -m32 -O0 -ggdb3 -fno-stack-protector \
-no-pie -mpreferred-stack-boundary=2 -o level3 level3.c
run this command to deactivate ASLR for this session : 
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
*/

int main()
{
    char name[20];

    printf("Welcome to the fourth level of binary exploitation workshop!\n");
    printf("You now have to make your own rop chain. Good luck.\n");
    fgets(name, 3000, stdin);

    printf("You entered : %s\n", name);

    //this_is_a_win_function();

    return 0;
}

