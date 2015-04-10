#!/bin/bash
# script para compilar todos los tests de un directorio
# hay que indicar el directorio donde estan los tests, las cabeceras y los fuentes
# pensado para usar en el makefile

testdir=$1
incdir=$2
srcdir=$3

for testsrc in $testdir/*.cpp
do
	nombre=${testsrc%.cpp}
	g++ -I$testdir/include -I$incdir -I$srcdir -o $nombre $testsrc
done