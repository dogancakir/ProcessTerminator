1. INTRODUCTION In part 1 of this project, it is expected that a system call which, kills processes according to given PID of process and given flag,  is written by us. Flag determines which processes associated with given PID will be killed.  If flag is 0, our system call kills just children of given process but if flag is 1, our system call kills children, siblings and children of siblings of given process. One of the most important point of this part is that system call works for just superuser(root). 
 
In part 2 of this project, it is expected to regularize the “exit” system call. Normally, when a process terminates, children of process are attached to other processes. Expectation of this assignment is that, when process terminates, children of this process are killed by system call in part 1. 
 
 
2. DEVELOPMENT & OPERATING ENVIRONMENT 
         The project is compiled and run successfully in Linux Lubuntu 13.04, 32 bit version.. Geany used as an editor. 
 
3. PREPARATIONS Before starting the project, we have to prepare the kernel for new version.  
 
Step1 : Extracting linux source 
        Firstly, linux source archive file is moved to Desktop. We have to write “sudo” before our code because we are working on kernel space becouse of that we have to be root user. 
 
->sudo mv /usr/src/linux-source-3.8.0/linux-source3.8.0.tar.bz2 linux-source3.8.0.tar.bz2 
 
After that operation, files are extracted. 
 
->tar -xjvf linux-source-3.8.0.tar.bz2 
 
Step2 : Creating a system call 
  A folder is created in “linux-source-3.8.0” folder, the name of the file is “my_process_terminator”. After that, a file is created in “my_process_terminator” called “my_process_terminator.c”. And a “Makefile” is created. 
 
Makefile obj-y := mycall.o 
 
Step3 : Modifying others Our system call is added to core-y in “Makefile” in /linux-source-3.8.0. 
 
core-y   := usr/ my_process_terminator/ 
Our system call is added to system call table. System call table is at “arch/x86/syscalls/syscall_32.tbl”. At the end of the table, system call is added like “351 i386 my_process_terminator sys_ my_process_terminator”. 
 
Our system call is added to system call headers. System call table is at “include/linux/syscalls.h”. At after the system calls, our system call is added like “asmlinkage long sys_my_process_terminator(pid_t pid, int flag);” 
 
We copy “config-3.8.13.6.txt” file to “linux-source-3.8.0” and rename it as “.config” 
 