<?php
function y($m) {
	$m = preg_replace("/\./", " x ", $m); // replace dots with x
	$m = preg_replace("/@/", " y", $m);   // replace @ with y
	return $m;
}

function x($y, $z) {
	$a = file_get_contents($y);
	$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); // replace [x ...] with y(...)
	$a = preg_replace("/\[/", "(", $a);                     // replace [ with (
	$a = preg_replace("/\]/", ")", $a);                     // replace ] with )
	return $a;
}

$r = x($argv[1], $argv[2]);
print $r;
