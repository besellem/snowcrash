We use Kali Linux to open `wireshark` with this file.  
In the middle of 
We get all the data found after the package containing the string `Password:`

```
66 74 5f 77 61 6e 64 72 7f 7f 7f 4e 44 52 65 6c 7f 4c 30 4c 0d
```

`7f` is the ASCII's delete character, meaning that each time it appears, we delete the previous character.  
The data is now : `66 74 5f 77 61 4e 44 52 65 4c 30 4c 0d`

Which decodes to : `ft_waNDReL0L`

Back to snowcrash's VM, we can now get the flag

```sh
$> su flag02
Password: ft_waNDReL0L

$> getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
```
