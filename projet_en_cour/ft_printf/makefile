# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/15 14:01:52 by mdambrev          #+#    #+#              #
#    Updated: 2018/03/27 21:45:10 by mdambrev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS 	= -g

NAME 	= libftprintf.a

SRC 	=	parsing.c\
			parsing_conv.c\
			ft_printf.c\
			set_content.c\
			set_content2.c\
			str_flag_transform.c\
			str_flag_space.c\
			set_wstr.c\
			put_printf.c\
			set_flag.c\
			set_decimal.c\
			set_wstr_space.c\
			transform_space.c\

LIBFT	=	circular_list.c\
			ft_atoi.c\
			ft_bzero.c\
			ft_convert_base.c\
			ft_itoa_max.c\
			ft_itoa_max.c\
			ft_memalloc.c\
			ft_memcpy.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_strlen.c\
			ft_strdup.c\
			ft_stringtonbr.c\
			ft_strlower.c\
			ft_strndup.c\
			ft_strnew.c\
			ft_strnew_bin.c\
			ft_wstradd.c\
			ft_wstradd2.c\
			ft_charchr.c\
			ft_isdigit.c\
			ft_memdel.c\
			ft_putwchar.c\
			ft_strchr.c\
			ft_strjoin.c\
			ft_strsub.c\
			ft_strupper.c\
			ft_toupper.c\

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
	gcc $(FLAGS) -o $@  -c $< -I $(INC_DIR) -I $(INC_LIBFT)

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p obj
	gcc $(FLAGS) -o $@ -c $< -I $(INC_LIBFT)

$(NAME): $(OBJ_LIBFT_O) $(OBJ_SRC_O)
	@ar rc $(NAME) $(OBJ_LIBFT_O) $(OBJ_SRC_O)
	ranlib $(NAME)

clean :
	@rm -rf $(OBJ_LIBFT_O) $(OBJ_SRC_O)

fclean : clean
	@rm -rf $(NAME) ./obj

norminette :
	@norminette $(LIBFT_PATH) $(SRC_PATH)

re: fclean all
