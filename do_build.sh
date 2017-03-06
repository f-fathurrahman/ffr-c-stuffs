#!/bin/bash
basn=`basename $1 .c`

gcc -Wall $1 -o $basn.x

