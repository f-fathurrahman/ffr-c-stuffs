INC1=/usr/include/glib-2.0/
INC2=/usr/lib/x86_64-linux-gnu/glib-2.0/include/
LIB="-lglib-2.0"

bas=`basename $1 .c`
gcc -I$INC1 -I$INC2 $1 $LIB -o $bas.x
