Preload the lib:
export LD_PRELOAD=/path/to/lib.so

how to test:
-make
-preload the lib
-gcc test.c
-./a.out

u can check env to see your lib preload

dont forget to:
-unset LD_PRELOAD
