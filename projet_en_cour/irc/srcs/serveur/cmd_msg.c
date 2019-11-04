/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:07:13 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 14:10:01 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int			check_message(t_env *e, int cs, char **tab)
{
	char	*str;
	char	*str1;

	str = "- Error too few arguments /msg Usage : /msg <username> <message>\n";
	str1 = "- Error missing message Usage : /msg <username> <message>\n";
	if (tab[1] == NULL || tab[1][0] == '\n')
		write_cs(e, cs, ft_strdup(str), ft_strlen(str));
	else if (tab[2] == NULL || tab[2][0] == '\n')
		write_cs(e, cs, ft_strdup(str1), ft_strlen(str1));
	else
		return (1);
	return (0);
}

int			check_if_user_exist(t_env *e, char **tab)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && e->fds[i].name)
		{
			if (ft_strcmp(e->fds[i].name, tab[1]) == 0)
				return (i);
		}
		i++;
	}
	return (0);
}

char		*add_infos(char *to_add)
{
	char *tmp;
	char *tmp2;

	tmp2 = "<";
	tmp = ft_strjoin(tmp2, to_add);
	to_add = tmp;
	tmp = ft_strjoin(to_add, "> have send you : ");
	free(to_add);
	to_add = tmp;
	if (tmp[ft_strlen(tmp) - 1] == '\n')
		tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}

char		*get_message(t_env *e, int cs, char *to_add)
{
	char	*to_cut;
	int		x;
	char	*tmp;
	char	*tmp1;

	x = 0;
	to_cut = ft_strdup(e->fds[cs].buf_read);
	tmp = to_cut;
	while (to_cut && x < 2)
	{
		if (to_cut[0] == ' ')
			x++;
		to_cut++;
	}
	tmp1 = add_infos(to_add);
	to_add = ft_strjoin(tmp1, to_cut);
	free(tmp);
	free(tmp1);
	return (to_add);
}

void		send_message(t_env *e, int cs, char **tab)
{
	int		cs_client;
	char	*msg_to_send;

	if (!check_message(e, cs, tab))
		return ;
	if ((cs_client = check_if_user_exist(e, tab)) == 0)
	{
		msg_to_send = "- Error: User doesn't exist\n";
		write_cs(e, cs, ft_strdup(msg_to_send), ft_strlen(msg_to_send));
	}
	else
	{
		msg_to_send = get_message(e, cs, e->fds[cs].name);
		write_cs(e, cs_client, ft_strdup(msg_to_send), ft_strlen(msg_to_send));
		free(msg_to_send);
	}
}
