/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:56:00 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/04 17:03:58 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int					main(int ac, char **av)
{
	char			**file_tab;
	int				x;

	x = 0;
	if ((file_tab = check_args(ac, av)) == NULL)
		return (EXIT_FAILURE);
	while (file_tab[x] != 0)
	{
		if (map(file_tab[x], ac, 1) == -1)
			break ;
		x++;
	}
	free_tab(file_tab);
	return (0);
}
