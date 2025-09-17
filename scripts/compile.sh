#! /bin/bash

cd ../compiler

cmake ./
make

rm -rf ../bin
mkdir ../bin
cp tea ../bin/tea
rm tea

echo "TEA binary is in: ../bin"

if [ $# -eq 1 ] && (($1 == "run"))
then
    ../bin/tea
fi