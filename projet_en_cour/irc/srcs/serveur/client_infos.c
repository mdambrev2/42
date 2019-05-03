/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:53:12 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/30 16:53:02 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "bircd.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

char		*get_client_name(t_env *env, int cs)
{
	char *client_number;
	char ret[50];
	char *tmp;
	
	if(env->fds[cs].name == NULL)
	{
		tmp = ft_itoa(cs);
		memset(ret, 0, 50);
		client_number = NULL;
		strcat(ret, "client#");
		strcat(ret, tmp);
		free(tmp);
		return(strdup(ret));
	}
	else
		return(strdup(env->fds[cs].name));
}

char		*client_leave_message(t_env *env, int cs)
{
	char ret[100];
	char *str;

	memset(ret, 0, 100);
	str = get_client_name(env, cs);
	strcat(ret, str);
	free(str);
	strcat(ret, ": has left the serveur\n");
	return(strdup(ret));
}

char		*client_join_message(t_env *env, int cs)
{
	char ret[100];
	char *str;

	memset(ret, 0, 100);
	str = get_client_name(env, cs);
	strcat(ret, str);
	free(str);
	strcat(ret, ": has join the serveur\n");
	return(strdup(ret));
}
