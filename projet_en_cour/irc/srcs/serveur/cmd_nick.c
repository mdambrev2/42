/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:33:36 by mdambrev          #+#    #+#             */
/*   Updated: 2019/05/03 18:15:02 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bircd.h>

void	change_nick_name(t_env *e, int cs, char **tab)
{
	char *str;
	char *tmp;

	str = get_client_name(e, cs);
	tmp = ft_strjoin(str, " has changed Nick name to ");
	free(str);	
	if(tab[1][strlen(tab[1]) - 1] == '\n')
		tab[1][strlen(tab[1]) - 1] = '\0';
	str = ft_strjoin(tmp, tab[1]);
	free(tmp);
	tmp = ft_strjoin(str, "\n");
	free(str);
	str = tmp;
	if(e->fds[cs].name)
		free(e->fds[cs].name);
	e->fds[cs].name = strdup(tab[1]);
	write_all_client_in_chan_with_cs(e, cs, str, strlen(str));
}

int		is_already_us(t_env *e, char **tab)
{
	int i;
	char *tmp;

	i = 0;
	tmp = strdup(tab[1]);
	if(tmp[strlen(tmp) - 1] == '\n')
		tmp[strlen(tmp) - 1] = '\0';
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT)
		{
			if(strcmp(tmp, e->fds[i].name) == 0)
			{
				free(tmp);
				return(0);
			}
		}
		i++;
	}
	free(tmp);
	return(1);
}

int		nick_cmd(t_env *e, int cs, char **tab)
{

	if(tab[1] == NULL)
		send(cs, "\nError /nick Usage : /nick <nickname>\n", 39, 0);
	else if(strlen(tab[1]) > 9)
		send(cs, "\nError: Nickname too long\n", 27, 0);
	else if(tab[2] != NULL)
		send(cs, "\nError /nick Usage : /nick <nickname>\n", 39, 0);
	else if(!is_already_us(e, tab))
		send(cs, "\nError /nick : Nickname is already use\n", 39, 0);
	else 
		change_nick_name(e, cs, tab);
	return(0);
}


