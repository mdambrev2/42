/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_leave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:11:46 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 14:09:22 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int			check_leave(t_env *e, int cs, char **tab)
{
	char	*str;

	if (tab[1] != NULL)
	{
		str = "- Error too many argument Usage : /leave\n";
		write_cs(e, cs, ft_strdup(str), ft_strlen(str));
	}
	else if (ft_strcmp(e->fds[cs].chan, "Default Irc") == 0)
	{
		str = "- Error you cannot leave <default irc> channel\n";
		write_cs(e, cs, ft_strdup(str), ft_strlen(str));
	}
	else
		return (1);
	return (0);
}

void		cmd_leave(t_env *e, int cs, char **tab)
{
	char	*str;
	char	*tmp;

	str = e->fds[cs].name;
	if (!check_leave(e, cs, tab))
		return ;
	else
	{
		str = ft_strjoin(str, " have leave channel: ");
		tmp = ft_strjoin(str, e->fds[cs].chan);
		write_all_client_in_chan_with_cs(e, cs, tmp, ft_strlen(tmp));
		free(e->fds[cs].chan);
		free(str);
		e->fds[cs].chan = ft_strdup("Default Irc");
	}
}
