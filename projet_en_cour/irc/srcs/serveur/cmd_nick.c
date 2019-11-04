/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:33:36 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 14:10:25 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <serveur.h>

void		change_nick_name(t_env *e, int cs, char **tab)
{
	char	*str;
	char	*tmp;

	str = get_client_name(e, cs);
	tmp = ft_strjoin(str, " has changed Nick name to ");
	free(str);
	if (tab[1][ft_strlen(tab[1]) - 1] == '\n')
		tab[1][ft_strlen(tab[1]) - 1] = '\0';
	str = ft_strjoin(tmp, tab[1]);
	free(tmp);
	tmp = ft_strjoin(str, "\n");
	free(str);
	str = tmp;
	if (e->fds[cs].name)
		free(e->fds[cs].name);
	e->fds[cs].name = ft_strdup(tab[1]);
	write_all_client_in_chan_with_cs(e, cs, str, ft_strlen(str));
}

int			is_already_us(t_env *e, char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(tab[1]);
	if (tmp[ft_strlen(tmp) - 1] == '\n')
		tmp[ft_strlen(tmp) - 1] = '\0';
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT)
		{
			if (ft_strcmp(tmp, e->fds[i].name) == 0)
			{
				free(tmp);
				return (0);
			}
		}
		i++;
	}
	free(tmp);
	return (1);
}

int			nick_cmd(t_env *e, int cs, char **tab)
{
	char	*str;
	char	*str2;
	char	*str3;

	str = "Error /nick Usage : /nick <nickname>\n";
	str2 = "Error: Nickname too long\n";
	str3 = "Error /nick : Nickname is already use\n";
	if (tab[1] == NULL || tab[1][0] == '\n')
		write_cs(e, cs, ft_strdup(str), ft_strlen(str));
	else if (ft_strlen(tab[1]) > 9)
		write_cs(e, cs, ft_strdup(str2), ft_strlen(str2));
	else if (tab[2] != NULL)
		write_cs(e, cs, ft_strdup(str), ft_strlen(str));
	else if (!is_already_us(e, tab))
		write_cs(e, cs, ft_strdup(str3), ft_strlen(str3));
	else
		change_nick_name(e, cs, tab);
	return (0);
}
