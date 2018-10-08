# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/15 14:01:52 by mdambrev          #+#    #+#              #
#    Updated: 2018/10/08 10:57:06 by mdambrev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS 	= -Wall -Werror -Wextra 

NAME1 	= ft_nm\

NAME2	= ft_otool\

SRC_MAIN =	nm_main.c\
			otool_main.c\

SRC 	=	put_nm_add.c\
			put_otool_add.c\
			parsing_args.c\
			handle_nm_64.c\
			nm_data_64.c\
			handle_nm_32.c\
			nm_data_32.c\
			nm_add_list.c\
			nm_sort_list.c\
			handle_fat_nm.c\
			handle_fat_otool.c\
			handle_ar.c\
			handle_otool_64.c\
			handle_otool_32.c\
			nm_otool_core.c\
			corrupted_file_x64_x32.c\
			corrupted_file_fat.c\
			corrupted_file_ar.c\
			nm_otool_utils.c\
			get_segment.c\
			no_leaks.c\
			nm_otool_map.c\

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
			ft_strncmp.c\
			ft_convert_base.c\
			ft_convert_base_suite.c\
			circular_list.c\
			ft_strcmp.c\
			ft_strstr.c\
			ft_strchr.c\
			ft_strend.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
		
OBJ_DIR = ./obj
SRC_DIR = ./srcs
LIBFT_DIR = ./libft
INC_DIR = ./includes
INC_LIBFT = ./libft/includes

OBJ_LIBFT = $(addprefix $(OBJ_DIR)/, $(LIBFT))
OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC))
OBJ_SRC_MAIN = $(addprefix $(OBJ_DIR)/, $(SRC_MAIN))


OBJ_LIBFT_O = $(OBJ_LIBFT:.c=.o)
OBJ_SRC_O = $(OBJ_SRC:.c=.o)
OBJ_SRC_MAIN_O = $(OBJ_SRC_MAIN:.c=.o)

all: $(NAME1) $(NAME2)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	@gcc $(FLAGS) -o $@  -c $< -I $(INC_DIR) -I $(INC_LIBFT)

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p obj
	@gcc $(FLAGS) -o $@ -c $< -I $(INC_LIBFT)

$(NAME1): $(OBJ_LIBFT_O) $(OBJ_SRC_O) $(OBJ_SRC_MAIN_O)
	@gcc $(FLAGS) -o $(NAME1) $(OBJ_SRC_O) $(OBJ_LIBFT_O)  ./obj/nm_main.o -L. -lftprintf

$(NAME2): $(OBJ_LIBFT_O) $(OBJ_SRC_O) $(OBJ_SRC_MAIN_O)
	@gcc $(FLAGS) -o $(NAME2) $(OBJ_SRC_O) $(OBJ_LIBFT_O) ./obj/otool_main.o -L. -lftprintf

clean :
	@rm -rf $(OBJ_LIBFT_O) $(OBJ_SRC_O) ./obj

fclean : clean
	@rm -rf $(NAME) libft_malloc.so ./obj 

re: fclean all
