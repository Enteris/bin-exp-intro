# Binary Exploitation Workshop

## System Protection
### Compiling
When compiling your binary, compile it as 32bit executable. It is a lot simpler to reverse engineer 32bit binaries than 64bit one. Also make sure stacks canaries are removed. You can compile the application with the following command line
```bash
gcc -m32 -fno-stack-protector -z execstack -no-pie -mpreferred-stack-boundary=2 -o program program.c
```
This will remove Stack Canaries, Allow the stack to be executable (NX bit off), will remove the Position Independent Executable (PIE), Align the stack on 2bytes and compile in 32bits.

Note : To compile in 32bit on a 64bit OS, you need to install the following libraries :
`sudo apt-get install libc6-dev-i386 gcc-multilib`

You may also add the `-ggdb` option to increase the amount of debug information available in the binary.



### ASLR
A kernel protection for binary exploitation is the Adress Space Layout Randomization (ASLR). It randomize the location of the stack when the binary is loaded in memory. To disable ASLR for the current session, use the following command : 
```bash
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
```
It will be re-activated on reboot. You can also reactivate it by doing 
```bash
echo 2 | sudo tee /proc/sys/kernel/randomize_va_space
```