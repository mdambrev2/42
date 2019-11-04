/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:36:51 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/12 16:39:39 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/socket.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <libft.h>
# define FD_FREE	0
# define FD_SERV	1
# define FD_CLIENT	2
# define BUF_SIZE	4096
# define MAX(a,b)	((a > b) ? a : b)

# define USAGE		"Usage: %s addr port\n"

typedef struct	s_fd
{
	int			type;
	char		*new_addr;
	int			new_port;
	char		*name;
	void		(*fct_read)();
	void		(*fct_write)();
	char		buf_read[BUF_SIZE + 1];
	char		buf_write[BUF_SIZE + 1];
	char		buf[BUF_SIZE + 1];
}				t_fd;

typedef struct	s_env
{
	t_fd		*fds;
	int			port;
	int			maxfd;
	int			sock;
	int			max;
	int			r;
	fd_set		fd_read;
	fd_set		fd_write;
}				t_env;

void			print_prompt(t_env *env);
int				write_server_sock(int cs);
int				get_server_connection(char *addr, int port);
char			*get_opt(int ac, char **argv, int *port, char *addr);
void			main_loop(t_env *e);
void			srv_create(t_env *e, int port);
void			srv_accept(t_env *e, int s);
void			client_read(t_env *e, int cs);
void			client_write(t_env *e, int cs);
void			clean_fd(t_env *e, int cs);
void			init_fd(t_env *e);
void			do_select(t_env *e);
int				check_fd(t_env *e);
int				client_connect(t_env *e);
void			run_client(int port, char *addr);
void			init_env(t_env *e, int port, char *addr);
void			clean_prompt(t_env *e);

#endif
