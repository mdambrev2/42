# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/15 14:01:52 by mdambrev          #+#    #+#              #
#    Updated: 2018/05/14 13:04:12 by mdambrev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS 	= -Wall -Werror -Wextra 

NAME1 	= ft_nm

NAME2	= ft_otool

SRC 	=	malloc.c\
			zone_alloc.c\
			new_zone.c\
			malloc_list.c\
			set_data_list.c\
			defrag.c\
			check_free.c\
			rase_free.c\
			realloc.c\
			check_realloc.c\
			put_memory.c\
			replace_free.c\
			put_memory_norm.c\

LIBFT	=	ft_strlen.c\
			ft_putstr.c\
			ft_putchar.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_put_hexa.c\
			ft_putnbr.c\
			ft_nbrlen.c\
			ft_atoi.c\
			ft_itoa.c\
			ft_memalloc.c\
		
OBJ_DIR = ./obj
SRC_DIR = ./srcs
LIBFT_DIR = ./libft
INC_DIR = ./includes
INC_LIBFT = ./libft/includes

OBJ_LIBFT = $(addprefix $(OBJ_DIR)/, $(LIBFT))
OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC))

OBJ_LIBFT_O = $(OBJ_LIBFT:.c=.o)
OBJ_SRC_O = $(OBJ_SRC:.c=.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	@gcc $(FLAGS) -o $@  -c $< -I $(INC_DIR) -I $(INC_LIBFT)

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p obj
	@gcc $(FLAGS) -o $@ -c $< -I $(INC_LIBFT)

$(NAME): $(OBJ_LIBFT_O) $(OBJ_SRC_O)
		@gcc $(FLAGS) -shared -o $(NAME) $(OBJ_SRC_O) $(OBJ_LIBFT_O)
		@ln -fs $(NAME) libft_malloc.so

clean :
	@rm -rf $(OBJ_LIBFT_O) $(OBJ_SRC_O) ./obj

fclean : clean
	@rm -rf $(NAME) libft_malloc.so ./obj 

re: fclean all
