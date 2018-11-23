/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_reply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:40:06 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 06:05:11 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int					get_fork_stat(char *cmd)
{
	pid_t			pid;
	int				status;
	struct rusage	rusage;
	char			**cmd_tab;
	char			*bin_path;

	cmd_tab = ft_strsplit(cmd, ' ');
	bin_path = ft_strjoin("/bin/", cmd_tab[0]);
	pid = fork();
	if (pid > 0)
	{
		wait4(0, &status, 0, &rusage);
		if (WIFEXITED(status))
			if ((WEXITSTATUS(status) > 0 && ft_strcmp(cmd_tab[0], "ls") == 0)
				|| (WEXITSTATUS(status) == 64
					&& (ft_strcmp(cmd_tab[0], "rm") == 0
						|| ft_strcmp(cmd_tab[0], "mkdir") == 0)))
				swap_to_error(1);
	}
	else
		execv(bin_path, cmd_tab);
	ft_strdel(&bin_path);
	free_tab(cmd_tab);
	return (0);
}

void				put_stdin(int cs, char *cmd, char *racine_serv)
{
	int				pid2;
	char			c[2];

	close(1);
	close(2);
	pid2 = dup2(cs, 1);
	if (secure_cmd(cmd, racine_serv, 1) == -1)
		printf("\n");
	get_fork_stat(cmd);
	c[0] = EOF;
	c[1] = '\n';
	write(1, c, 2);
	dup2(40, 1);
	dup2(41, 2);
}

void				put_client_cmd(int cs, char *cmd,
						int n_client, char *racine_serv)
{
	int				pid1;
	int				pid2;
	char			c[2];
	char			*tmp;

	printf("\n\033[1;32mSucess Client %d : Execute \"%s\" \n\033[00m"
		, n_client, cmd);
	send_string(cs, "GOOD CMD\n");
	tmp = ft_strdup(cmd);
	dup2(1, 40);
	close(1);
	pid1 = dup2(2, 41);
	close(2);
	pid2 = dup2(cs, 2);
	write(2, "\n", 2);
	if (secure_cmd(tmp, racine_serv, 1) == -1)
		swap_to_error(1);
	get_fork_stat(tmp);
	ft_strdel(&tmp);
	c[0] = EOF;
	c[1] = '\n';
	dup2(1, 40);
	put_stdin(cs, cmd, racine_serv);
}

int					is_builtins(char *cmd)
{
	char			*cmp_tab[6];
	char			*tmp;

	cmp_tab[0] = "cd";
	cmp_tab[1] = "get";
	cmp_tab[2] = "put";
	cmp_tab[3] = "pwd";
	cmp_tab[4] = "quit";
	cmp_tab[5] = 0;
	if ((tmp = if_exist_in_tab(cmp_tab, cmd)) != NULL)
	{
		ft_strdel(&tmp);
		return (1);
	}
	else
		return (0);
}

int					client_reply(int cs, char *str,
									int n_client, char *racine_serv)
{
	char			**cmd_tab;
	char			*cmd;
	char			*ret;

	set_null(&cmd, &ret);
	if (str && str[0] != '\0')
	{
		cmd_tab = ft_strsplit("ls mkdir pwd cd rm get put quit", ' ');
		ret = dup_occu_by_delim(str, ' ', 0);
		cmd = if_exist_in_tab(cmd_tab, ret);
		free_tab(cmd_tab);
	}
	if ((str == NULL || str[0] == '\0') || cmd == NULL)
		put_client_error(cs, str, n_client);
	else if (is_builtins(ret) == 0)
		put_client_cmd(cs, str, n_client, racine_serv);
	ft_strdel(&cmd);
	if (is_builtins(ret) == 1)
	{
		ft_strdel(&ret);
		if (put_client_builtins(cs, str, n_client, racine_serv) == -1)
			return (-1);
	}
	ft_strdel(&ret);
	return (0);
}
