/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 13:05:41 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/08 21:24:09 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H

# define FT_P_H

# include <libft.h>
#include <stdio.h>
#include <libft.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Server
int     create_server(int port);
pid_t   start_multiple_connection(int sock, int *cs, int *n_client);
int     put_new_connection(void);
void    put_connection_lost(int client_number);
int     client_reply(int cs, char *str, int n_client,  char *racine_serv);
int     client_contact(int cs, int n_client);
void    put_client_builtins(int cs, char *cmd, int n_client, char *racine_serv);
// Client

int	    write_server_sock(int cs);
int     get_server_connection(char *addr, int port);
int     put_client_connection(int cs);
int     receive_server_instruction(int sock);
#endif
