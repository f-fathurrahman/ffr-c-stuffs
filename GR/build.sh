#!/bin/bash
basn=`basename $1 .c`

export GRDIR=/home/efefer/mysoftwares/gr
gcc -Wall -I$GRDIR/include $1 -o $basn.x -L$GRDIR/lib -lGR -lm

