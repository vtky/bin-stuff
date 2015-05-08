## Is binary stack executable?
`readelf -l <bin>`

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
      GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 __RW__  0x4

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
