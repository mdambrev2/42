/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:47:39 by mdambrev          #+#    #+#             */
/*   Updated: 2019/05/03 18:13:37 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

int		check_join(int cs, char **tab)
{
	if(tab[1] == NULL)
		send(cs, "Error /join Usage : /join <chan_name>\n", 39, 0);
	else if(tab[2] != NULL)
		send(cs, "Error /join Usage : /join <chan_name>\n", 39, 0);
	else
		return(1);
	return(0);
}

void	cmd_join(t_env *e, int cs, char **tab)
{
	char *msg;
	char *tmp;

	if(!check_join(cs, tab))
		return;
	free(e->fds[cs].chan);
	e->fds[cs].chan = strdup(tab[1]);
	msg = e->fds[cs].name;
	tmp = ft_strjoin(msg, " have join channel : ");
	msg = ft_strjoin(tmp, tab[1]);
	free(tmp);
	write_all_client_in_chan_with_cs(e, cs, msg, strlen(msg));
}
