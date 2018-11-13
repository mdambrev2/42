/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 00:18:04 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/14 00:50:28 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int			get_file_server(int cs, char *racine_serv)
{
	char c[2];

	dup2(1, 40);
	close(1);
	dup2(cs, 1);

	printf("get server %d %s\n",cs , racine_serv);

	c[0] = -1;
	c[1] = '\n';
	write(1, c, 2);
	dup2(40, 1);
	return(0);
}
