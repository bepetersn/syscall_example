
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

- [X] The output from /var/log/syslog or dmesg showing the printk()'s
- [X] The C source code for my test programs
- [X] This README. Contains my contact information, information on what each file contains, information on where each file should be located in a standard build tree, instructions for building and running your test program


--------------------------------------

### Files (More info)

#### cs3753_add.c

This is the source file for the "cs3753_add" syscall which I added to the kernel. From the root of the linux source directory (linux root), it needs to be placed in the arch/<your architecture>/kernel/ directory (I used "x86" arch -- writing it that way from here on). This will be built into an object file (.o) and then included
with the kernel.

#### Makefile

I modified this file, also present from <linux root>/arch/x86/kernel directory. This is the Makefile for the kernel, used for making it easier to compile all its C programs with the GCC via something like `make && make module_installs && make install`. Makefiles consist of a set of targets and intelligently determine how to build or re-build files based on their extension. This is extended by the `kbuild` system with the concept of "goal definitions", beginning with "obj-y" or "obj-m" (or variables to be substituted in with "y" or "m"). 

I added a line, `obj-y += cs3753_add.o` to tell the Makefile
to build and include the cs3753.o file as a built-in with the kernel.

#### syscall_64.tbl

This is the architecture-specific system call entry table for x86 64-bit processor systems. It includes rows of system calls which each have 4 fields specified: an ID, an ABI (Application Binary Interface -- either "common", "x32", or "64"), the name of the system call, and the name of the function which defines that system call.

I added a line to this file for sys_cs3753_add with a new ID.

#### syscalls.h

This is a non-architecture-specific C header file for the defined system calls, where each line is the function prototype for a syscall. 

I added a function prototype for sys_cs3753_add here. 

#### dmesg_tail_20.txt

You can see the text output of my running `dmesg | tail -n 20 > dmesg_tail_20.txt` here, right after running my `./my_sum` program. 

#### my_sum.c / my_sum

This is the source code / executable file I created to show the functionality of the sys_cs3753_add system call. Instructions below for building and running.

To build it, just call:
 
    make my_sum

To run it, you can call it like so:

    ./my_sum 6 7

Where two arguments follow the executable. Two integers will be added and the result displayed, as well as logged to /var/log/syslog. There's several undefined behaviors around this script, so be careful to always call it with two small-ish integers.


#### 

Just a license for this code because it is hosted on GitHub.
