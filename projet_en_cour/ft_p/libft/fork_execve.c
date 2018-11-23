/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:47:27 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 07:40:10 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

int					get_fork(char *cmd)
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
		wait4(0, &status, 0, &rusage);
	else
		execv(bin_path, cmd_tab);
	free_tab(cmd_tab);
	ft_strdel(&bin_path);
	return (0);
}
