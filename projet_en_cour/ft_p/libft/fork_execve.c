/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:47:27 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/29 16:09:59 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

int get_fork(char *bin_path, char **cmd_tab)
{
	pid_t			pid;
	int				status;
	struct rusage	*rusage;

	pid = fork();
	if(pid > 0)
		wait4(0, &status, 0, rusage);
	else
		execv(bin_path, cmd_tab);
	return(0);
}

int	fork_execv(char *cmd)
{
	char **cmd_tab;
	char *tab[5];
	char *bin_path;

	tab[0] = "ls";
	tab[1] = "mkdir";
	tab[2] = "pwd";
	tab[3] = NULL;
	cmd_tab = ft_strsplit(cmd, ' ');
	if(if_exist_in_tab(tab, cmd_tab[0]))
		bin_path = ft_strjoin("/bin/", cmd_tab[0]);
	else 
		return(-1);
	get_fork(bin_path, cmd_tab);
	return(0);
}
