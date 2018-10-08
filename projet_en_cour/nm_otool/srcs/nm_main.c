/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:31:53 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/08 10:45:12 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int					main(int ac, char **av)
{
	char			**file_tab;
	int				x;
	int				ret;

	x = 0;
	ret = 0;
	if ((file_tab = check_args(ac, av)) == NULL)
		return (EXIT_FAILURE);
	while (file_tab[x] != 0)
	{
		if (map(file_tab[x], ac, 0) == -1)
			ret = 1;
		x++;
	}
	free_tab(file_tab);
	return (ret);
}
