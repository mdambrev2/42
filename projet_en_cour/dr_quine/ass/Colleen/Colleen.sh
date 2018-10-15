#!/bin/bash

NAME="Colleen"

~/.brew/bin/nasm -f macho64 $NAME.s
gcc	-Wall -Werror -Wall $NAME.o -o Colleen
rm	Colleen.o

if [ "$1" == "diff" ]
then
	./Colleen > tmp_Colleen.s
	diff Colleen.s tmp_Colleen.s
fi

if [ "$1" == "exec" ]
then
	./Colleen
fi
