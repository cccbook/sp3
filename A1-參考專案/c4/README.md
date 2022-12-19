# C4 -- 500 行的 C 語言編譯器 (修改版, 所以改叫 C5)

C in four functions

* 修改者 -- 陳鍾誠
* 作者 -- https://github.com/rswier/
* 來源 -- https://github.com/rswier/c4

## 使用方式

```

$ ./c4 test/hello.c
hello, world
exit(0) cycle = 9


$ ./c4 test/sum.c
sum(10)=55
exit(0) cycle = 303
```

## 印出組合語言 (堆疊機)

```

$ ./c4 -s test/sum.c
1: #include <stdio.h>
2:
3: // sum(n) = 1+2+...+n
4: int sum(int n) {
5:   int s;
6:   int i;
7:   s=0;
    ENT  2
    LEA  -1
    PSH
    IMM  0
    SI
8:   i=1;
    LEA  -2
    PSH
    IMM  1
    SI
9:   while (i <= n) {
    LEA  -2
    LI  
    PSH
    LEA  2
    LI
    LE
    BZ   0
10:     s = s + i;
    LEA  -1
    PSH
    LEA  -1
    LI
    PSH
    LEA  -2
    LI  
    ADD 
    SI  
11:     i ++;
    LEA  -2
    PSH
    LI
    PSH
    IMM  1
    ADD
    SI  
    PSH
    IMM  1
    SUB
12:   }
13:   return s;
    JMP  6946956
    LEA  -1
    LI
    LEV 
14: }
    LEV
15:
16: int main() {
17:   printf("sum(10)=%d\n", sum(10));
    ENT  0
    IMM  7209048
    PSH 
    IMM  10
    PSH
    JSR  6946900
    ADJ  1
    PSH
    PRTF
    ADJ  2
18:   return 0;
    IMM  0
    LEV
19: }
    LEV
```

## 自我編譯

```
$ ./c4 test/hello.c
hello, world
exit(0) cycle = 9


$ ./c4 c4.c test/hello.c
hello, world
exit(0) cycle = 9
exit(0) cycle = 26036


$ ./c4 c4.c c4.c test/hello.c
hello, world
exit(0) cycle = 9
exit(0) cycle = 26036
exit(0) cycle = 10271482
```

## 在 64 位元平台上使用 (例如 Linux 64 位元版，應該加上 -m32)

```
guest@localhost:~/sp2/project/c5$ gcc -m32 c4.c -o c4
guest@localhost:~/sp2/project/c5$ ./c4 test/hello.c
hello, world
exit(0) cycle = 9
```
