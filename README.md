# test-hook-linux-internal
Linux Interal Test using my![ Memory lib](https://github.com/rdbo/Memory) (backup branch)  

# How to compile?
Run the following command:  
```
$ ./compile.sh
```

# How to inject?
Check out my video: https://youtu.be/HiOUnvNKhZ0  
... or just open GDB and run the following commands:  
```
(gdb) attach <PROCESS_ID_HERE>
(gdb) set $dlopen = (void*(*)(char*, int)) dlopen
(gdb) call $dlopen("build/libinject.so", 1)
(gdb) continue
```
