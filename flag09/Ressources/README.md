```sh
$> ls -l ~
-rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09 level09   26 Mar  5  2016 token

$> cat token
[some binary data]

$> ./level09 'aaaa'
abcd
```

My assertion is that the token has been encrypted by the `flag09` program.  
`level09` substracts each byte by its value and its index, we can use this algorithm to decrypt the token.

Dowload the `token` locally (with flag08) and compile `convert_back.c`:
```sh
$> scp -P4242 level09@192.168.56.102:/home/user/level09/token ~/Downloads/
Password: 25749xKZ8L7DkSCwJkT9dyv6f

$> gcc -o convert_back convert_back.c
```

You can now pass the token as an argument to `convert_back`:
```sh
$> ./convert_back ~/Downloads/token
f3iji1ju5yuevaus41q1afiuq
```

Back in the VM, we now have the token:
```
$> su flag09
Password: f3iji1ju5yuevaus41q1afiuq

$> getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```
