/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_serv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:28:19 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/20 00:39:40 by mdambrev         ###   ########.fr       */
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
	printf("\n");
	if(secure_cmd(cmd, racine_serv, 1) == -1)
	{
		swap_to_error(1);
		printf("\n");
	}
	if((str = get_occu_by_delim(cmd, ' ', 1)) == NULL || str[0] == '\0')
		str = ft_strdup(racine_serv);
	if(ft_cd(str, 1, racine_serv) == -1)
		swap_to_error(1);
	printf("\n");
	c[0] = EOF;
	c[1] = '\n';
	write(1, c, 2);
	dup2(pid1, 1);
	close(pid1);
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
		printf("\nWorking Directory : /\n\n");
	else
		printf("\nWorking Directory : %s\n\n", str + x);
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

	printf("\nExit Sucess\n\n");

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
	printf("\n\033[1;32mSucess Client %d : \"%s\" Good server command\033[00m\n", n_client, cmd);
	if(ft_strcmp(str, "put") == 0)
	{
		send_string(cs, "PUT\n");
		return(put_file_server(cs, cmd));
	}
	if(ft_strcmp(str, "get") == 0)
	{
		send_string(cs, "GET\n");
		return(get_file_server(cs, cmd));
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
