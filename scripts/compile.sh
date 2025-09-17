#! /bin/bash

cd ../compiler

cmake ./
make

rm -rf ../bin
mkdir ../bin
cp tea ../bin/tea
rm tea

if [ $# -eq 1 ] && (($1 == "run"))
then
    ../bin/tea
fi