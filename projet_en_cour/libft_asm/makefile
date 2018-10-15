#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/23 13:20:45 by mdambrev          #+#    #+#              #
#    Updated: 2015/05/16 21:10:17 by mdambrev         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	= libfts.a

FLAGS 	= -Wall -Wextra -Werror

FLAGS_NSM = -f macho64

SRC_ASS = ft_tolower.s\
		  ft_toupper.s\
		  ft_isprint.s\
		  ft_isascii.s\
		  ft_isalnum.s\
		  ft_isdigit.s\
		  ft_isalpha.s\
		  ft_strlen.s\
		  ft_strcat.s\
		  ft_strdup.s\
		  ft_memset.s\
		  ft_memcpy.s\
		  ft_cat.s\
		  ft_bzero.s\
		  ft_puts.s\
		  ft_strnew.s\
		  ft_strclr.s\
		  ft_memalloc.s\
		  ft_isupper.s\
		  ft_islower.s\

NASM = ~/.brew/Cellar/nasm/2.11.08/bin/nasm
OBJDIR = ./obj/
SRC_ASSDIR = ./srcs_ass/
INCDIR  = ./includes/
SRCS_ASS = $(addprefix $(SRC_ASSDIR), $(SRC_ASS))
OBJS 	= $(SRCS_ASS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.s
	@$(NASM) $(FLAGS_NSM) $< 

clean: 
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

compil: re
	@gcc -o test srcs/main.c libfts.a -I ./includes


