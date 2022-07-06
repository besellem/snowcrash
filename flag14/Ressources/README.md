We try to get the flag directly inside `/bin/getflag`.  

```
$> gdb /bin/getflag
[...]
(gdb) b main
(gdb) r
(gdb) jump *0x08048de5
Continuing at 0x8048de5.
7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
[...]

$> su flag14
Password: 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)

$> getflag
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
```
