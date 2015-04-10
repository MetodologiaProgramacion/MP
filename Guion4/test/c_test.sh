#!/bin/bash
# Forma rapida de compilar un test
# El unico parametro es el nombre del test a compilar

testdir=.
srcdir=../src
incdir=../include
testsrc=$1

nombre=${testsrc%.cpp}
g++ -I$testdir/include -I$incdir -I$srcdir -o $nombre $testsrc