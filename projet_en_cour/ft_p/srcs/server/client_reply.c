/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_reply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:40:06 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/06 20:56:17 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	put_client_cmd(int cs, char *cmd, int n_client)
{

	printf("Good Client %d : Is a cmd %s\n",n_client , cmd);
	send_data(cs, "GOOD CMD", 10);
}

void	put_client_error(int cs, char *str, int n_client)
{
		printf("Error Client %d : \"%s\" is not a server command\n", n_client, str);
		send_data(cs, "BAD CMD", 9);
}

int		client_reply(int cs, char *str, int n_client)
{
	char **cmd_tab;
	char *cmd;
	char *cmd_dup;

	int x;

	x = 0;
	if(str == NULL)
		return(0);
	cmd_tab = ft_strsplit("ls mkdir pwd cd rm get set", ' ');
	cmd_dup = dup_occu_by_delim(str, ' ', 0);
	init_connection(cs);
	if((cmd = if_exist_in_tab(cmd_tab , cmd_dup)) != NULL)
		put_client_cmd(cs, cmd, n_client);
	else
		put_client_error(cs, str, n_client);
	done_connection(cs);
	return(0);	
}
