# 組合語言與機器碼

```
$ cd .\03-fib\
$ gcc -fverbose-asm -S fib.c -o fib.s
$ gcc -c fib.c -o fib.o
$ gcc main.c fib.c -o fib
$ ./fib
fib(10)=89
```

## 組合語言

```
    .file    "fib.c"
    .text
    .globl    _fib
    .def    _fib;    .scl    2;    .type    32;    .endef
_fib:
    pushl    %ebp     #                 # 前置堆疊框架處理
    movl    %esp, %ebp     #,
    pushl    %ebx     #
    subl    $20, %esp     #,
    cmpl    $1, 8(%ebp)     #, n        # if n <=1
    jg    L2     #,
    movl    $1, %eax     #, D.1493      #    eax= 1  ... return
    jmp    L3     #
L2:
    movl    8(%ebp), %eax     # n, tmp93 # eax = n
    subl    $1, %eax     #, D.1493       # eax = eax - 1
    movl    %eax, (%esp)     # D.1493,   # 推入參數 n-1
    call    _fib     #                   # 呼叫 fib(n-1)
    movl    %eax, %ebx     #, D.1493     # 取得傳回值放入 ebx
    movl    8(%ebp), %eax     # n, tmp94 # eax = n
    subl    $2, %eax     #, D.1493       # eax = eax - 2
    movl    %eax, (%esp)     # D.1493,   # 推入參數 n-2
    call    _fib     #                   # 呼叫 fib(n-2)
    addl    %ebx, %eax     # D.1493, D.1493 # eax = fib(n-1)+fib(n-2)
L3:
    addl    $20, %esp     #,              # 堆疊後置段，恢復 ebp, esp 的值 
    popl    %ebx     #
    popl    %ebp     #
    ret                                   # return
    .ident    "GCC: (tdm-1) 5.1.0"
```

## 機器碼

```

$ objdump -s fib.o

fib.o:     file format pe-i386

Contents of section .text:
 0000 5589e553 83ec1483 7d08017f 07b80100  U..S....}.......
 0010 0000eb20 8b450883 e8018904 24e8deff  ... .E......$...
 0020 ffff89c3 8b450883 e8028904 24e8ceff  .....E......$...
 0030 ffff01d8 83c4145b 5dc39090           .......[]...
Contents of section .rdata$zzz:
 0000 4743433a 20287464 6d2d3129 20352e31  GCC: (tdm-1) 5.1
 0010 2e300000                             .0..
PS D:\ccc\book\sp\code\c\03-asm\03-fib> objdump -d fib.o

fib.o:     file format pe-i386


Disassembly of section .text:

00000000 <_fib>:
   0:   55                      push   %ebp
   1:   89 e5                   mov    %esp,%ebp
   3:   53                      push   %ebx
   4:   83 ec 14                sub    $0x14,%esp
   7:   83 7d 08 01             cmpl   $0x1,0x8(%ebp)
   b:   7f 07                   jg     14 <_fib+0x14>
   d:   b8 01 00 00 00          mov    $0x1,%eax
  12:   eb 20                   jmp    34 <_fib+0x34>
  14:   8b 45 08                mov    0x8(%ebp),%eax
  17:   83 e8 01                sub    $0x1,%eax
  1a:   89 04 24                mov    %eax,(%esp)
  1d:   e8 de ff ff ff          call   0 <_fib>
  22:   89 c3                   mov    %eax,%ebx
  24:   8b 45 08                mov    0x8(%ebp),%eax
  27:   83 e8 02                sub    $0x2,%eax
  2a:   89 04 24                mov    %eax,(%esp)
  2d:   e8 ce ff ff ff          call   0 <_fib>
  32:   01 d8                   add    %ebx,%eax
  34:   83 c4 14                add    $0x14,%esp
  37:   5b                      pop    %ebx
  38:   5d                      pop    %ebp
  39:   c3                      ret
  3a:   90                      nop
  3b:   90                      nop
```