## ASLR

	cat /proc/sys/kernel/randomize_va_space

__0__
Disable ASLR. This setting is applied if the kernel is booted with the norandmaps boot parameter.

__1__
Randomize the positions of the stack, virtual dynamic shared object (VDSO) page, and shared memory regions. The base address of the data segment is located immediately after the end of the executable code segment.

__2__
Randomize the positions of the stack, VDSO page, shared memory regions, and the data segment. This is the default setting.