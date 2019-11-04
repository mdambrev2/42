/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 13:05:41 by mdambrev          #+#    #+#             */
/*   Updated: 2019/05/10 18:49:19 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H

# define FT_P_H
# include <libft.h>
# include <stdio.h>
# include <libft.h>
# include <sys/socket.h>
# include <netdb.h>
# include <unistd.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <dirent.h>

int		create_server(int port);
pid_t	start_multiple_connection(int sock, int *cs, int *n_client, int x);
int		put_new_connection(void);
void	put_connection_lost(int client_number, int cs);
int		client_reply(int cs, char *str, int n_client, char *racine_serv);
int		client_contact(int cs, int n_client);
int		put_client_builtins(int cs, char *cmd, int n_client, char *racine_serv);
char	*stock_cwd(int x);
void	wait_child(void);
int		put_file_server(int cs, char *cmd);
int		get_file_server(int cs, char *racine_serv);
int		swap_to_error(int x);
void	put_client_error(int cs, char *str, int n_client);
void	set_null(char **cmd, char **ret);
int		write_server_sock(int cs);
int		get_server_connection(char *addr, int port);
int		put_client_connection(int cs);
int		receive_server_instruction(int sock);
int		read_instruction(int sock);
int		put_file_client(int cs);
int		get_file_client(int cs);
char	*get_client_infos(int x, int ret, char *str);

#endif
