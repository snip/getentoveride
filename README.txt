http://www.technovelty.org/code/c/override.html
http://cvsweb.netbsd.org/bsdweb.cgi/src/usr.bin/getent/getent.c?rev=1.18&content-type=text/x-cvsweb-markup

gcc -shared -fPIC -o liboverride.so override.c -ldl
LD_PRELOAD=./liboverride.so getent services mail
LD_PRELOAD=./liboverride.so getent services port_1851
