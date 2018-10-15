#!/bin/bash

NAME="Sully"

~/.brew/bin/nasm -f macho64 $NAME.s
gcc	-Wall -Werror -Wall -g $NAME.o -o Sully

if [ "$1" == "diff" ]
then
	./$NAME
	diff $NAME.s Sully_5.s
fi

if [ "$1" == "exec" ]
then
	./Sully
fi
