/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_who.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:18:49 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 14:10:44 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

char			*get_list_of_user(char *str)
{
	static char *ret = NULL;
	char		*tmp;

	if (str == NULL)
	{
		tmp = ft_strjoin(ret, "\n");
		free(ret);
		ret = NULL;
		return (tmp);
	}
	if (ret == NULL)
		ret = ft_strdup("\n- Active User list : \n\n");
	tmp = ret;
	ret = ft_strjoin(ret, str);
	free(tmp);
	tmp = ret;
	ret = ft_strjoin(ret, "\n");
	free(tmp);
	return (NULL);
}

void			cmd_who(t_env *e, int cs)
{
	int			i;
	char		*str;

	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT
				&& !ft_strcmp(e->fds[i].chan, e->fds[cs].chan))
		{
			get_list_of_user(e->fds[i].name);
		}
		i++;
	}
	str = get_list_of_user(NULL);
	write_cs(e, cs, ft_strdup(str), ft_strlen(str));
	free(str);
}
