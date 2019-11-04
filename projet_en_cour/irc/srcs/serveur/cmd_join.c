/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:47:39 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 15:24:22 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int			check_join(t_env *e, int cs, char **tab)
{
	char	*str;

	str = "- Error /join Usage : /join <chan_name>\n";
	if (tab[1] == NULL || tab[1][0] == '\n')
		write_cs(e, cs, ft_strdup(str), ft_strlen(str));
	else if (tab[2] != NULL)
		write_cs(e, cs, ft_strdup(str), ft_strlen(str));
	else
		return (1);
	return (0);
}

void		cmd_join(t_env *e, int cs, char **tab)
{
	char	*msg;
	char	*tmp;

	if (!check_join(e, cs, tab))
		return ;
	free(e->fds[cs].chan);
	e->fds[cs].chan = ft_strdup(tab[1]);
	msg = e->fds[cs].name;
	tmp = ft_strjoin(msg, " have join channel : ");
	msg = ft_strjoin(tmp, tab[1]);
	free(tmp);
	write_all_client_in_chan_with_cs(e, cs, msg, ft_strlen(msg));
}
