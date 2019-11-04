/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:53:12 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 13:59:40 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "serveur.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

char		*get_client_name(t_env *env, int cs)
{
	char	*client_number;
	char	ret[50];
	char	*tmp;

	if (env->fds[cs].name == NULL)
	{
		tmp = ft_itoa(cs);
		ft_memset(ret, 0, 50);
		client_number = NULL;
		ft_strcat(ret, "client#");
		ft_strcat(ret, tmp);
		free(tmp);
		return (ft_strdup(ret));
	}
	else
		return (ft_strdup(env->fds[cs].name));
}

char		*client_leave_message(t_env *env, int cs)
{
	char	ret[100];
	char	*str;

	ft_memset(ret, 0, 100);
	str = get_client_name(env, cs);
	ft_strcat(ret, str);
	free(str);
	printf("%s has left server\n", ret);
	ft_strcat(ret, ": has left server\n");
	return (ft_strdup(ret));
}

char		*client_join_message(t_env *env, int cs)
{
	char	ret[100];
	char	*str;

	ft_memset(ret, 0, 100);
	str = get_client_name(env, cs);
	ft_strcat(ret, str);
	free(str);
	ft_strcat(ret, ": has join the serveur\n");
	return (ft_strdup(ret));
}
