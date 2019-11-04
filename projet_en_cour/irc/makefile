# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/15 14:01:52 by mdambrev          #+#    #+#              #
#    Updated: 2019/08/13 16:06:36 by mdambrev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS 	= -Wall -Werror -Wextra -g 

NAME1 	= serveur\

NAME2	= client\

SRC_SERV 	=	init_env.c init_fd.c check_fd.c clean_fd.c \
				client_infos.c client_write.c client_read.c client_write2.c\
				srv_create.c srv_accept.c do_select.c get_opt.c \
				main_loop.c main_serveur.c circular_buf.c \
				cmd_join.c cmd_leave.c cmd_msg.c cmd_nick.c cmd_who.c is_cmd.c \

SRC_CLIENT	= init_env.c init_fd.c check_fd.c clean_fd.c \
			  client_read.c client_write.c\
			  do_select.c get_opt.c \
			  main_loop.c client_main.c \
			  get_server_connection.c \
			  client_connect.c \
			  clean_prompt.c \

LIBFT	=	ft_strlen.c\
			ft_memset.c\
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
			ft_cd.c\
			ft_cd_2.c\
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
			ft_putchar_fd.c\
			ft_putstr_fd.c\

OBJ_DIR_CLIENT = ./obj/client
OBJ_DIR_SERVER = ./obj/server
OBJ_DIR_LIBFT = ./obj/libft
SRC_SERVER_DIR = ./srcs/serveur
SRC_CLIENT_DIR = ./srcs/client

LIBFT_DIR = ./libft
INC_CLIENT = ./includes/
INC_SERVEUR = ./includes/
INC_LIBFT = ./libft/includes

OBJ_LIBFT = $(addprefix $(OBJ_DIR_LIBFT)/, $(LIBFT))
OBJ_SERVER_SRC = $(addprefix $(OBJ_DIR_SERVER)/, $(SRC_SERV))
OBJ_CLIENT_SRC = $(addprefix $(OBJ_DIR_CLIENT)/, $(SRC_CLIENT))

OBJ_LIBFT_O = $(OBJ_LIBFT:.c=.o)
OBJ_SERVER_O = $(OBJ_SERVER_SRC:.c=.o)
OBJ_CLIENT_O = $(OBJ_CLIENT_SRC:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ_LIBFT_O) $(OBJ_SERVER_O)
	@gcc $(FLAGS) -o $(NAME1) $(OBJ_SERVER_O) $(OBJ_LIBFT_O)

$(NAME2): $(OBJ_LIBFT_O) $(OBJ_CLIENT_O)
	@gcc $(FLAGS) -o $(NAME2) $(OBJ_CLIENT_O) $(OBJ_LIBFT_O)

$(OBJ_DIR_CLIENT)/%.o: $(SRC_CLIENT_DIR)/%.c
	@mkdir -p obj
	@mkdir -p obj/client
	gcc $(FLAGS) -o $@  -c $< -I $(INC_CLIENT) -I $(INC_LIBFT)

$(OBJ_DIR_SERVER)/%.o: $(SRC_SERVER_DIR)/%.c
	@mkdir -p obj
	@mkdir -p obj/server
	gcc $(FLAGS) -o $@  -c $< -I $(INC_SERVEUR) -I $(INC_LIBFT)

$(OBJ_DIR_LIBFT)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p obj
	@mkdir -p obj/libft
	gcc $(FLAGS) -o $@ -c $< -I $(INC_LIBFT)

clean :
	rm -rf $(OBJ_LIBFT_O) $(OBJ_SRC_O) ./obj

fclean : clean
	rm -rf $(NAME1) $(NAME2) ./obj 

re: fclean all
