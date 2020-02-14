#!/bin/bash
basn=`basename $1 .c`

if [ $basn == "$1" ]; then
  echo "Error: file name does not have *.c extension"
  exit 1
fi

# FIXME check if GRDIR is defined
export GRDIR=/home/efefer/mysoftwares/GR
gcc -Wall -I$GRDIR/include $1 -o $basn.x -L$GRDIR/lib -lGR -lm

