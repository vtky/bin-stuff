## Kali for ARM

    apt-get install build-essential gdb curl tree vim mlocate

### python pip

    wget https://bootstrap.pypa.io/get-pip.py

### Capstone and ROPgadget

    pip install capstone
    pip install ropgadget


## Is binary stack executable?

The flag on the GNU_STACK line will show if it has execute permissions

    # readelf -l <bin>

    Elf file type is EXEC (Executable file)
    Entry point 0x82fc
    There are 8 program headers, starting at offset 52

    Program Headers:
      Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
      EXIDX          0x00052c 0x0000852c 0x0000852c 0x00008 0x00008 R   0x4
      PHDR           0x000034 0x00008034 0x00008034 0x00100 0x00100 R E 0x4
      INTERP         0x000134 0x00008134 0x00008134 0x00019 0x00019 R   0x1
          [Requesting program interpreter: /lib/ld-linux-armhf.so.3]
      LOAD           0x000000 0x00008000 0x00008000 0x00538 0x00538 R E 0x8000
      LOAD           0x000538 0x00010538 0x00010538 0x00120 0x00124 RW  0x8000
      DYNAMIC        0x000544 0x00010544 0x00010544 0x000e8 0x000e8 RW  0x4
      NOTE           0x000150 0x00008150 0x00008150 0x00020 0x00020 R   0x4
      GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RW  0x4

     Section to Segment mapping:
      Segment Sections...
       00     .ARM.exidx
       01
       02     .interp
       03     .interp .note.ABI-tag .hash .dynsym .dynstr .gnu.version .gnu.version_r .rel.dyn .rel.plt .init .plt .text .fini .rodata .ARM.exidx .eh_frame
       04     .init_array .fini_array .jcr .dynamic .got .data .bss
       05     .dynamic
       06     .note.ABI-tag
       07


## Is binary compiled with PIE?

1. Check if binary is executable and not a library: PHDR is present
2. Elf file type should be: DYN


### Generating PIE binary

    gcc -o PIEdemo -fpie -fPIE -pie PIEdemo.c

    -fpic
        Generate position-independent code (PIC) suitable for use in a shared library, if supported for the target machine. Such code accesses all constant addresses through a global offset table (GOT). The dynamic loader resolves the GOT entries when the program starts (the dynamic loader is not part of GCC; it is part of the operating system). If the GOT size for the linked executable exceeds a machine-specific maximum size, you get an error message from the linker indicating that -fpic does not work; in that case, recompile with -fPIC instead. (These maximums are 8k on the SPARC and 32k on the m68k and RS/6000. The x86 has no such limit.)

        Position-independent code requires special support, and therefore works only on certain machines. For the x86, GCC supports PIC for System V but not for the Sun 386i. Code generated for the IBM RS/6000 is always position-independent.

        When this flag is set, the macros __pic__ and __PIC__ are defined to 1.
    -fPIC
        If supported for the target machine, emit position-independent code, suitable for dynamic linking and avoiding any limit on the size of the global offset table. This option makes a difference on the m68k, PowerPC and SPARC.

        Position-independent code requires special support, and therefore works only on certain machines.

        When this flag is set, the macros __pic__ and __PIC__ are defined to 2.
    -fpie
    -fPIE
        These options are similar to -fpic and -fPIC, but generated position independent code can be only linked into executables. Usually these options are used when -pie GCC option is used during linking.

        -fpie and -fPIE both define the macros __pie__ and __PIE__. The macros have the value 1 for -fpie and 2 for -fPIE.