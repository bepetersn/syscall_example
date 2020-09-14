
# Adding a syscall

These repo contains the requisite steps I took I needed to take in making my first system call (syscall) and re-compiling the kernel with the latter syscall. 

This was completed by Brian E. Peterson. You can reach me at brian.e.peterson@colorado.edu or bepetersondev@gmail.com.


### What is included

These files are included (in a flat directory struct`ure):

[X] ./arch/x86/kernel/cs3753_add.c
[X] ./arch/x86/kernel/Makefile
[X] ./arch/x86/entry/syscalls/syscall_64.tbl
[X] ./include/linux/syscalls.h

Additionally, these files are included for clarity of exposition:

- [] The output from /var/log/syslog or dmesg showing the printk()'s
- [X] The C source code for my test programs
- [X] This README. Contains my contact information, information on what each file contains, information on where each file should be located in a standard build tree, instructions for building and running your test program


--------------------------------------

### Files (More info)

#### cs3753_add.c

This is the source file for the "cs3753_add" syscall which I added to the kernel. From the root of the linux source directory, it needs to be placed in the arch/<your architecture>/kernel/ directory (I used "x86" arch -- writing it that way from here on).

#### Makefile

I modified this file, also present, from the root of the linux source directory, at the arch/x86/kernel directory. This is the Makefile for the kernel, used for making it easier to compile all its C programs with the GCC via `make && make module_installs && make install`.

#### syscall_64.tbl

This is the ... 

#### syscalls.h


### Building and runnning the test program
