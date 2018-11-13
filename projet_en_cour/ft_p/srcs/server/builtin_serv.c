/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_serv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:28:19 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/14 00:42:52 by mdambrev         ###   ########.fr       */
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
	if((str = get_occu_by_delim(cmd, ' ', 1)) == NULL || str[0] == '\0')
		str = ft_strdup(racine_serv);
	ft_cd(str, 1, racine_serv);
	c[0] = EOF;
	c[1] = '\n';
	write(1, c, 2);
	dup2(40, 1);
}

void	pwd_builtin(int cs, char *racine_serv)
{
	char c[2];
	char *str;
	int		x;

	dup2(1, 40);
	close(1);
	dup2(cs, 1);

	x = 0;
	str = (char *)malloc(sizeof(char) * 1024);
 	str = getcwd(str, 1024);
	while(str[x] && racine_serv[x] && str[x] == racine_serv[x])
		x++;
	if(str[x] == '\0')
		printf("Working Directory : /\n");
	else
		printf("Working Directory : %s\n", str + x);
	c[0] = EOF;
	c[1] = '\n';
	write(1, c, 2);
	dup2(40, 1);
}

int	quit_builtin(int cs)
{
	char c[2];

	dup2(1, 40);
	close(1);
	dup2(cs, 1);

	printf("Exit Sucess\n");

	c[0] = -2;
	c[1] = '\n';
	write(1, c, 2);
	dup2(40, 1);

	return(-1);
}

int	   put_client_builtins(int cs, char *cmd, int n_client,  char *racine_serv)
{
	char *str;

	str = dup_occu_by_delim(cmd, ' ', 0);
	printf("Sucess Client %d : \"%s\" Good server Builtin\n", n_client, cmd);
	if(ft_strcmp(str, "put") == 0)
	{
		send_string(cs, "PUT\n");
		return(put_file_server(cs, racine_serv));
	}
	if(ft_strcmp(str, "get") == 0)
	{
		send_string(cs, "GET\n");
		return(get_file_server(cs, racine_serv));
	}
	send_string(cs, "GOOD BUILTINS\n");
	if(ft_strcmp(str, "cd") == 0)
		cd_builtin(cs, cmd, racine_serv);
	if(ft_strcmp(str, "pwd") == 0)
		pwd_builtin(cs, racine_serv);
	if(ft_strcmp(str, "quit") == 0)
		return(quit_builtin(cs));
	return(0);
}
