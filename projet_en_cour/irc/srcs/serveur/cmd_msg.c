/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:07:13 by mdambrev          #+#    #+#             */
/*   Updated: 2019/05/03 18:14:11 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

int		check_message(int cs, char **tab)
{
	if(tab[1] == NULL)
		send(cs, "Error too few arguments /msg Usage : /msg <username> <message>\n", 64, 0);
	else if(tab[2] == NULL)
		send(cs, "Error missing message Usage : /msg <username> <message>\n", 57, 0);
	else
		return(1);
	return(0);
}

int			check_if_user_exist(t_env *e, char **tab)
{
	int i;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && e->fds[i].name)
		{
			if(strcmp(e->fds[i].name, tab[1]) == 0)
				return(i);
		}
		i++;
	}
	return(0);
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
	if(tmp[strlen(tmp) - 1] == '\n')
		tmp[strlen(tmp) - 1] = '\0';
	return(tmp);
}

char		*get_message(t_env *e, int cs, char *to_add)
{
	char *to_cut;
	int			x;

	x = 0;

	to_cut = strdup(e->fds[cs].buf_read);
	while(to_cut && x < 2)
	{
		if(to_cut[0] == ' ')
			x++;
		to_cut++;
	}
	to_add = add_infos(to_add);	
	to_add = ft_strjoin(to_add, to_cut);
	return(to_add);
}

void		send_message(t_env *e, int cs, char **tab)
{
	int		cs_client;
	char	*msg_to_send;

	if(!check_message(cs, tab))
		return;
	if((cs_client = check_if_user_exist(e, tab)) == 0)
	{
		msg_to_send = "Error: User doesn't exist\n";
		send(cs, msg_to_send, strlen(msg_to_send), 0);
	}
	else
	{
		msg_to_send = get_message(e, cs, e->fds[cs].name);
		send(cs_client, msg_to_send, strlen(msg_to_send), 0);
		free(msg_to_send);
	}
}
