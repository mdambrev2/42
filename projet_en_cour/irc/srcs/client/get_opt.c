/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:04:49 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 14:39:47 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "client.h"

char	*get_opt(int ac, char **argv, int *port, char *addr)
{
	if (ac == 1 || ac == 2)
		*port = 4242;
	if (ac > 3)
	{
		printf(USAGE, argv[0]);
		exit(1);
	}
	else if (ac == 2)
		addr = ft_strdup(argv[1]);
	else if (ac == 3)
	{
		addr = ft_strdup(argv[1]);
		*port = ft_atoi(argv[2]);
	}
	else if (ac == 1)
		addr = ft_strdup("127.0.0.1");
	if (ac > 1 && ft_strcmp(addr, "localhost") == 0)
	{
		free(addr);
		addr = ft_strdup("127.0.0.1");
	}
	return (addr);
}
