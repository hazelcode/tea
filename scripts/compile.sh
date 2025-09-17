#! /bin/bash

cd ../compiler

cmake ./ > ../scripts/compile.log
make >> ../scripts/compile.log

rm -rf ../bin
mkdir ../bin
cp tea ../bin/tea
rm tea

if [ $# -eq 1 ] && (($1 == "run"))
then
    ../bin/tea
else
    echo "TEA binary is in: ../bin"
    echo "Compilation logs were generated in: compile.log"
fi