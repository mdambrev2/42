/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_reply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:40:06 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/05 23:10:41 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	write_to_client(int cs, char *str)
{
	write(cs, str, ft_strlen(str));
}

void	put_client_cmd(int cs, char *cmd, int n_client)
{
	char eof;

	eof = EOF;

	printf("Good Client %d : Is a cmd %s\n",n_client , cmd);
	write_to_client(cs, "GOOD\n");
}

void	put_client_error(int cs, char *str, int n_client)
{
		char eof;

		eof = EOF;
		printf("Error Client %d : %s is not a server command\n", n_client, str);
		write_to_client(cs, "\nServer Command List :\n-ls ...\n-pwd ...\n-set ...\n");
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
	if((cmd = if_exist_in_tab(cmd_tab , cmd_dup)) != NULL)
		put_client_cmd(cs, cmd, n_client);
	else
		put_client_error(cs, cmd, n_client);
	return(0);	
}
