/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_serv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:28:19 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/08 22:32:41 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	cd_builtin(int cs, char *cmd, char *racine_serv)
{
	int pid1;
	int pid2;
	char c[2];
	char *str;;

	pid1 = dup2(1, 40);
	close(1);
	pid2 = dup2(cs, 1);
	secure_cmd(cmd, racine_serv);
	if((str = get_occu_by_delim(cmd, ' ', 1)) == NULL)
		str = ft_strdup(racine_serv);
	ft_cd(str, 1);
	c[0] = EOF;
	c[1] = '\n';
	write(1, c, 2);
	dup2(40, 1);
}

void    put_client_builtins(int cs, char *cmd, int n_client,  char *racine_serv)
{
	char *str;

	str = dup_occu_by_delim(cmd, ' ', 0);
	printf("Sucess Client %d : \"%s\" Good server Builtin\n", n_client, cmd);
	send_string(cs, "GOOD BUILTINS\n");
	if(ft_strcmp(str, "cd") == 0)
		cd_builtin(cs, cmd, racine_serv);	
}
