/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:21:19 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/13 14:29:00 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "serveur.h"

void	get_opt(t_env *e, int ac, char **av)
{
	if (ac > 2)
	{
		printf(USAGE, av[0]);
		exit(1);
	}
	if (ac == 1)
		e->port = 4242;
	else if (ac == 2)
		e->port = ft_atoi(av[1]);
}
