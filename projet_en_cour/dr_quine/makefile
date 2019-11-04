# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/15 14:01:52 by mdambrev          #+#    #+#              #
#    Updated: 2018/10/17 21:08:04 by mdambrev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR = ./obj

all: Colleen_c Grace_c Sully_c Colleen_s  Grace_s Sully_s

Colleen_c :
	@gcc $(FLAGS) ./c/Colleen/Colleen.c -o ./c/Colleen/Colleen

Grace_c :
	@gcc $(FLAGS) ./c/Grace/Grace.c -o ./c/Grace/Grace

Sully_c :
	@gcc $(FLAGS) ./c/Sully/Sully.c -o ./c/Sully/Sully

Colleen_s:
	~/.brew/bin/nasm -f macho64 ./ass/Colleen/Colleen.s
	gcc -Wall -Werror -Wall ./ass/Colleen/Colleen.o -o ./ass/Colleen/Colleen

Grace_s:
	~/.brew/bin/nasm -f macho64 ./ass/Grace/Grace.s
	gcc -Wall -Werror -Wall ./ass/Grace/Grace.o -o ./ass/Grace/Grace

Sully_s:
	~/.brew/bin/nasm -f macho64 ./ass/Sully/Sully.s
	gcc -Wall -Werror -Wall ./ass/Sully/Sully.o -o ./ass/Sully/Sully

clean :
	rm -f	./ass/Sully/Sully_*.o
	rm -f	./ass/Colleen/Colleen.o\
			./ass/Grace/Grace.o\
			./ass/Sully/Sully.o\

fclean : clean
	rm -f   ./ass/Sully/Sully_*
	rm -f   ./c/Sully/Sully_*
	rm -f	./c/Sully/Sully\
			./c/Colleen/Colleen\
			./c/Grace/Grace\
			./c/Grace/Grace_kid.c\
			./ass/Grace/Grace_kid.s\
			./ass/Colleen/Colleen\
			./ass/Grace/Grace\
			./ass/Sully/Sully\

re: fclean all
