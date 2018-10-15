#!/bin/bash

NAME="Grace"

~/.brew/bin/nasm -f macho64 $NAME.s
gcc	-Wall -Werror -Wall $NAME.o -o Grace
rm	Grace.o

if [ "$1" == "diff" ]
then
	./Grace
	diff $NAME.s Grace_kid.s
fi

if [ "$1" == "exec" ]
then
	./Grace
	cat Grace_kid.s
fi
