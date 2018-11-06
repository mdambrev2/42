# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/15 14:01:52 by mdambrev          #+#    #+#              #
#    Updated: 2018/11/06 18:23:29 by mdambrev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
GWW = GCC -Wall -Wextra -Werror
INC_LIB = ./includes/
SRC =		./ft_atoi.c \
				./data_serv.c \
				./get_str_end.c \
				./ft_cd.c \
				./ft_strcut.c \
				./ft_put_files_in_fd.c \
				./get_next_line.c \
				./ft_strend.c \
				./ft_charchr.c \
				./ft_strlower.c \
				./ft_strupper.c \
				./ft_convert_base.c \
				./ft_convert_base_suite.c \
				./ft_strndup.c \
				./ft_stringtonbr.c \
				./ft_bzero.c \
				./ft_isalnum.c \
				./ft_isalpha.c \
				./ft_isascii.c \
				./ft_isdigit.c \
				./ft_isprint.c \
				./ft_itoa.c \
				./ft_itoa_max.c \
				./ft_lstadd.c \
				./ft_lstdel.c \
				./ft_lstdelone.c \
				./ft_lstdup.c \
				./ft_lstiter.c \
				./ft_lstmap.c \
				./ft_lstnew.c \
				./ft_memalloc.c \
				./ft_memccpy.c \
				./ft_memchr.c \
				./ft_memcmp.c \
				./ft_memcpy.c \
				./ft_memdel.c \
				./ft_memmove.c \
				./ft_memset.c \
				./ft_nbrlen.c \
				./ft_putchar.c \
				./ft_putchar_fd.c \
				./ft_putendl.c \
				./ft_putendl_fd.c \
				./ft_putnbr.c \
				./ft_putnbr_fd.c \
				./ft_putstr.c \
				./ft_putstr_fd.c \
				./ft_strcat.c \
				./ft_strchr.c \
				./ft_strclr.c \
				./ft_strcmp.c \
				./ft_strcpy.c \
				./ft_strdel.c \
				./ft_strdup.c \
				./ft_strequ.c \
				./ft_striter.c \
				./ft_striteri.c \
				./ft_strjoin.c \
				./ft_strlcat.c \
				./ft_strlen.c \
				./ft_strmap.c \
				./ft_strmapi.c \
				./ft_strncat.c \
				./ft_strncmp.c \
				./ft_strncpy.c \
				./ft_strnequ.c \
				./ft_strnew.c \
				./ft_strnew_bin.c \
				./ft_strnstr.c \
				./ft_strrchr.c \
				./ft_strsplit.c \
				./ft_strstr.c \
				./ft_strsub.c \
				./ft_strtrim.c \
				./ft_tolower.c \
				./ft_toupper.c \
				./nb_word_str.c \
				./replace_char.c \
				./nb_char_str.c \
				./d_list.c \
				./d_list2.c \
				./d_list3.c \
				./circular_list.c \
				./ft_nbrlen.c \
				./ft_wstradd.c \
				./ft_wstradd2.c \
				./ft_putwchar.c \
				./circular_list_add_inblock.c \
				./swap_uint.c \
				./if_exist_in_tab.c \
				./get_occu_by_delim.c \

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): 
	@gcc -c $(SRC) -I $(INC_LIB)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME) 

clean :
	@rm -rf $(OBJ)
fclean : clean
	@rm -rf $(NAME)
norminette :
	@norminette libft.h $(SRC)
re: fclean all
