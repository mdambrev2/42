/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:08:22 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 14:11:04 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int			go_cmd(t_env *e, int cs)
{
	char	**tab;
	char	*tmp;

	tmp = "Unknown Command\n";
	tab = ft_strsplit(e->fds[cs].buf_read, ' ');
	if (tab[0][ft_strlen(tab[0]) - 1] == '\n')
		tab[0][ft_strlen(tab[0]) - 1] = '\0';
	if (ft_strcmp(tab[0], "/join") == 0)
		cmd_join(e, cs, tab);
	else if (ft_strcmp(tab[0], "/leave") == 0)
		cmd_leave(e, cs, tab);
	else if (ft_strcmp(tab[0], "/who") == 0)
		cmd_who(e, cs);
	else if (ft_strcmp(tab[0], "/nick") == 0)
		nick_cmd(e, cs, tab);
	else if (ft_strcmp(tab[0], "/msg") == 0)
		send_message(e, cs, tab);
	else
		write_cs(e, cs, ft_strdup(tmp), ft_strlen(tmp));
	free_tab(tab);
	return (0);
}
