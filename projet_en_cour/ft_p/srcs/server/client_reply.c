/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_reply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:40:06 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/08 21:48:41 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"


void	put_client_cmd(int cs, char *cmd, int n_client, char *racine_serv)
{
	int pid1;
	int pid2;
	char c[2];
	char *tmp;

	printf("Sucess Client %d : \"%s\" Good server command\n", n_client, cmd);
	send_string(cs, "GOOD CMD\n");

	tmp = ft_strdup(cmd);	
	
	dup2(1, 40);
	close(1);
	pid1 = dup2(2, 41);
	close(2);
	pid2 = dup2(cs, 2);
	write(2, "\n", 2);
	secure_cmd(tmp, racine_serv);
	get_fork(tmp);
	c[0] = EOF;
	c[1] = '\n';
	dup2(1, 40);


	
	
	
	close(1);
	close(2);
	pid2 = dup2(cs, 1);
	secure_cmd(cmd, racine_serv);
	get_fork(cmd);
	c[0] = EOF;
	c[1] = '\n';
	write(1, c, 2);
	dup2(40, 1);
	dup2(41, 2);


}

void	put_client_error(int cs, char *str, int n_client)
{
		printf("Error Client %d : \"%s\" is not a server command\n", n_client, str);
		send_string(cs, "BAD CMD\n");
}

int 	is_builtins(char *cmd)
{
	char *cmp_tab[5];

	cmp_tab[0] = "cd";
	cmp_tab[1] = "get";
	cmp_tab[2] = "set";
	cmp_tab[3] = "pwd";
	cmp_tab[4] = 0;
	if(if_exist_in_tab(cmp_tab , cmd) != NULL)
		return(1);
	else 
		return(0);
}

int		client_reply(int cs, char *str, int n_client, char *racine_serv)
{
	char **cmd_tab;
	char *cmd;
	char *ret;

	if(str && str[0] != '\0')
	{
		cmd_tab = ft_strsplit("ls mkdir pwd cd rm get set", ' ');
		ret = dup_occu_by_delim(str, ' ' ,0);
		cmd = if_exist_in_tab(cmd_tab , ret);
	}
	if(str == NULL || str[0] == '\0')
		cmd = NULL;
	if(cmd == NULL)	
		put_client_error(cs, str, n_client);
	else if(is_builtins(ret) == 0)
	{
		put_client_cmd(cs, str, n_client, racine_serv);
	}
	else if(is_builtins(ret) == 1)
		put_client_builtins(cs, str, n_client, racine_serv);
	return(0);	
}
