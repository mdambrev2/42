/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:32:15 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 12:05:35 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include "serveur.h"

void					srv_create(t_env *e, int port)
{
	int					s;
	struct sockaddr_in	sin;
	struct protoent		*pe;

	pe = (struct protoent*)getprotobyname("tcp");
	if ((s = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
	{
		printf("Connection Failure \n");
		exit(-1);
	}
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);
	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
	{
		printf("Bind Error : Port is already use\n");
		exit(-1);
	}
	listen(s, 42);
	e->fds[s].type = FD_SERV;
	e->fds[s].fct_read = srv_accept;
}
