# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/15 14:01:52 by mdambrev          #+#    #+#              #
#    Updated: 2019/04/11 18:13:03 by mdambrev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS 	= -Wall -Werror -Wextra -g 

NAME1 	= server\

NAME2	= client\

SRC_SERV 	= server_main.c\
			  start_server_connection.c\
			  put_server_info.c\
			  client_reply.c\
			  builtin_serv.c\
			  put_file_server.c\
			  get_file_server.c\

SRC_CLIENT	= client_main.c\
			  get_server_connection.c\
			  put_client_info.c\
			  receive_server_instruction.c\
			  put_file_client.c\
			  get_file_client.c\

LIBFT	=	ft_strlen.c\
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
			ft_strsplit.c\
			ft_strjoin.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			get_occu_by_delim.c\
			data_receive.c\
			fork_execve.c\
			get_next_line.c\
			secure_cmd.c\
			secure_folder.c\
			get_str_end.c\
			data_send.c\
		
OBJ_DIR = ./obj
SRC_SERVER_DIR = ./srcs/server
SRC_CLIENT_DIR = ./srcs/client

LIBFT_DIR = ./libft
INC_DIR = ./includes
INC_LIBFT = ./libft/includes

OBJ_LIBFT = $(addprefix $(OBJ_DIR)/, $(LIBFT))
OBJ_SERVER_SRC = $(addprefix $(OBJ_DIR)/, $(SRC_SERV))
OBJ_CLIENT_SRC = $(addprefix $(OBJ_DIR)/, $(SRC_CLIENT))

OBJ_LIBFT_O = $(OBJ_LIBFT:.c=.o)
OBJ_SERVER_O = $(OBJ_SERVER_SRC:.c=.o)
OBJ_CLIENT_O = $(OBJ_CLIENT_SRC:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ_LIBFT_O) $(OBJ_SERVER_O)
	@gcc $(FLAGS) -o $(NAME1) $(OBJ_SERVER_O) $(OBJ_LIBFT_O)

$(NAME2): $(OBJ_LIBFT_O) $(OBJ_CLIENT_O)
	@gcc $(FLAGS) -o $(NAME2) $(OBJ_CLIENT_O) $(OBJ_LIBFT_O)

$(OBJ_DIR)/%.o: $(SRC_CLIENT_DIR)/%.c
	@mkdir -p obj
	@gcc $(FLAGS) -o $@  -c $< -I $(INC_DIR) -I $(INC_LIBFT)

$(OBJ_DIR)/%.o: $(SRC_SERVER_DIR)/%.c
	@mkdir -p obj
	@gcc $(FLAGS) -o $@  -c $< -I $(INC_DIR) -I $(INC_LIBFT)

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@mkdir -p obj
	@gcc $(FLAGS) -o $@ -c $< -I $(INC_LIBFT)

clean :
	@rm -rf $(OBJ_LIBFT_O) $(OBJ_SRC_O) ./obj

fclean : clean
	@rm -rf $(NAME1) $(NAME2) ./obj 

re: fclean all
