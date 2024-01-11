#!/bin/bash
make -C .. -s all
mv ../writing.a ./
make -C .. -s fclean
cc testmain.c writing.a -o test.a
./test.a
rm test.a