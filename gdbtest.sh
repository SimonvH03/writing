#!/bin/bash
make -s all clean
cc ft_writing.c writing.a -o test.a -g
gdb test.a