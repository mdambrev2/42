/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_accept.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:26:36 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 14:05:04 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "serveur.h"

void						srv_accept(t_env *e, int s)
{
	int						cs;
	struct sockaddr_in		csin;
	socklen_t				csin_len;
	char					*str;

	csin_len = sizeof(csin);
	cs = accept(s, (struct sockaddr*)&csin, &csin_len);
	printf("New client#%d from %s:%d\n", cs,
			inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
	str = client_join_message(e, cs);
	e->fds[cs].name = get_client_name(e, cs);
	e->fds[cs].chan = ft_strdup("Default Irc");
	write_all_client(e, cs, str, ft_strlen(str));
	clean_fd(&e->fds[cs]);
	e->fds[cs].type = FD_CLIENT;
	e->fds[cs].fct_read = client_read;
	e->fds[cs].fct_write = client_write;
}
