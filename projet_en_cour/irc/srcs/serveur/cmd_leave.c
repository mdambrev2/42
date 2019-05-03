/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_leave.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:11:46 by mdambrev          #+#    #+#             */
/*   Updated: 2019/05/03 15:39:05 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

int     check_leave(t_env *e, int cs, char **tab)
{
	char *str;

	if(tab[1] != NULL)
	{
		str = "Error too many argument Usage : /leave\n";
		send(cs, str, strlen(str), 0);
	}
	else if(strcmp(e->fds[cs].chan, "Default Irc") == 0)
	{
		str = "Error you cannot leave <Default Irc> chan\n";
		send(cs, str, strlen(str), 0);
	}
	else
		return(1);
	return(0);
}


void	cmd_leave(t_env *e, int cs,  char **tab)
{
	char *str;
	char *tmp;

	str = e->fds[cs].name;
	if(!check_leave(e, cs, tab))
		return;
	else
	{
		str = ft_strjoin(str, " have leave a channel: ");
		tmp = ft_strjoin(str, e->fds[cs].chan);
		write_all_client_in_chan_with_cs(e, cs, tmp, strlen(tmp));
		free(e->fds[cs].chan);
		free(str);
		e->fds[cs].chan = strdup("Default Irc");

	}
}
