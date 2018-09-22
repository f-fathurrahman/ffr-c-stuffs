#!/bin/bash
basn=`basename $1 .c`

if [ $basn == "$1" ]; then
  echo "Error: file name does not have *.c extension"
  exit 1
fi

export GRDIR=/home/efefer/mysoftwares/gr
gcc -Wall -I$GRDIR/include $1 -o $basn.x -L$GRDIR/lib -lGR -lm

