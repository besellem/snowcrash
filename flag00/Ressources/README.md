```sh
$> find / -user flag00 2>/dev/null
[...]
/usr/sbin/john

$> cat /usr/sbin/john
cdiiddwpgswtgt
```

After a little bit of research, I found that this password is encoded with ceasar code.
When decoded, the password is `nottoohardhere`.

```sh
$> su flag00
Password: nottoohardhere

$> getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
```
