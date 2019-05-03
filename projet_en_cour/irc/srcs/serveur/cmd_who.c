/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_who.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:18:49 by mdambrev          #+#    #+#             */
/*   Updated: 2019/05/03 14:12:03 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bircd.h"

char	*get_list_of_user(char *str)
{
	static char *ret = NULL;
	char *tmp;

	if(str == NULL)
	{
		tmp = ft_strjoin(ret, "\n");
		free(ret);
		ret = NULL;
		return(tmp);
	}
	if(ret == NULL)
		ret = "\nList of Active User : \n\n";
	ret = ft_strjoin(ret, str);
	tmp = ret;
	ret = ft_strjoin(ret, "\n");
	return(NULL);
}

void	cmd_who(t_env *e, int cs)
{
	int i;
	char *str;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && !strcmp(e->fds[i].chan, e->fds[cs].chan))
		{
			get_list_of_user(e->fds[i].name);
		}
		i++;
	}
	str = get_list_of_user(NULL);
	send(cs, str, strlen(str), 0);
}
