#!/bin/bash
basn=`basename $1 .c`

mpicc -Wall -I ~/mysoftwares/petsc-3.7.5/include/ $1 -L ~/mysoftwares/petsc-3.7.5/lib -lpetsc -o $basn.x

