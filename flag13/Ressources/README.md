```sh
$> echo 'int getuid(void) { return (4242); }' > /tmp/getuid.c
$> gcc -shared -o /tmp/getuid.so /tmp/getuid.c

$> cat << EOF > /tmp/script.sh
> #!/bin/sh
> export LD_LIBRARY_PATH=/tmp
> export LD_PRELOAD=/tmp/getuid.so
> $@

$> chmod +x /tmp/script.sh

$> /tmp/script.sh id
uid=4242(root) gid=2013(level13) groups=2013(level13),100(users)
```

It doesn't work on `~/level13` so I tried gdb instead:

```
(gdb) b main
(gdb) r
(gdb) ni
(gdb) ni
(gdb) ni
(gdb) ni
(gdb) info registers eax
eax            0x7dd	2013
(gdb) p $eax=4242
$1 = 4242
(gdb) n
your token is 2A31L79asukciNyi8uppkEuSx
```
