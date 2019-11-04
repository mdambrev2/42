# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/15 14:01:52 by mdambrev          #+#    #+#              #
#    Updated: 2019/10/01 13:25:15 by mdambrev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS 	= -Wall -Werror -Wextra -g 

NAME1 	= ft_ssl\

SRC_SSL 	=	main.c \
				parsing_argv.c \
				usage.c \
				check_stdin.c \
				check_string.c \
				check_file.c \
				get_md5.c \
				get_sha.c \
				utils.c

LIBFT	=	ft_strlen.c\
			ft_memset.c\
			ft_strsub.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_putstr.c\
			ft_putendl.c\
			ft_putchar.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_put_hexa.c\
			ft_putnbr.c\
			ft_nbrlen.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_memalloc.c\
			ft_strncmp.c\
			ft_convert_base.c\
			ft_convert_base_suite.c\
			get_occu_by_delim.c\
			circular_list.c\
			static_file.c\
			if_exist_in_tab.c\
			ft_strdup.c\
			ft_strndup.c\
			ft_strcmp.c\
			ft_strstr.c\
			ft_strchr.c\
			ft_strend.c\
			ft_strnew.c\
			ft_strcat.c\
			ft_strsplit.c\
			ft_strjoin.c\
			ft_tolower.c\
			ft_toupper.c\
			get_next_line.c \
			ft_putchar_fd.c\
			ft_putstr_fd.c\

OBJ_DIR_SSL = ./obj/ft_ssl
OBJ_DIR_LIBFT = ./obj/libft
SRC_SSL_DIR = ./srcs

LIBFT_DIR = ./libft
INC_SSL = ./includes/
INC_LIBFT = ./libft/includes

OBJ_LIBFT = $(addprefix $(OBJ_DIR_LIBFT)/, $(LIBFT))
OBJ_SSL_SRC = $(addprefix $(OBJ_DIR_SSL)/, $(SRC_SSL))

OBJ_LIBFT_O = $(OBJ_LIBFT:.c=.o)
OBJ_SSL_O = $(OBJ_SSL_SRC:.c=.o)

all: $(NAME1)

$(NAME1): $(OBJ_LIBFT_O) $(OBJ_SSL_O)
	@gcc $(FLAGS) -o $(NAME1) $(OBJ_SSL_O) $(OBJ_LIBFT_O) -L. -lftprintf

$(OBJ_DIR_SSL)/%.o: $(SRC_SSL_DIR)/%.c
	@mkdir -p obj
	@mkdir -p obj/ft_ssl
	@gcc $(FLAGS) -o $@  -c $< -I $(INC_SSL) -I $(INC_LIBFT) 

$(OBJ_DIR_LIBFT)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p obj
	@mkdir -p obj/libft
	@gcc $(FLAGS) -o $@ -c $< -I $(INC_LIBFT)

clean :
	@rm -rf $(OBJ_LIBFT_O) $(OBJ_SRC_O) ./obj

fclean : clean
	@rm -rf $(NAME1) ./obj 

re: fclean all
