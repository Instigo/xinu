#!/bin/sh

make clean -C compile;make -C compile;
cd compile
./upload.sh
cd ../
