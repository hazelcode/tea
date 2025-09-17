#! /bin/bash

cd ../compiler

cmake ./
make

rm -rf ../bin
mkdir ../bin
cp build/tea ../bin/tea

if [ $# -eq 1 ] && (($1 == "run"))
then
    ../bin/tea
fi