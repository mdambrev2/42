/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:53:03 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/08 09:34:24 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

char		**create_a_out_tab(void)
{
	char	**ret;

	ret = (char **)ft_memalloc(sizeof(char *) * 2);
	ret[0] = ft_strdup("a.out");
	ret[1] = 0;
	return (ret);
}

char		**create_file_tab(int ac, char **av)
{
	char	**ret;
	int		x;

	x = 0;
	ret = (char **)ft_memalloc(sizeof(char *) * ac);
	while (x < ac - 1)
	{
		ret[x] = ft_strdup(av[x + 1]);
		x++;
	}
	return (ret);
}

char		**check_args(int ac, char **av)
{
	if (ac < 2)
		return (create_a_out_tab());
	else
		return (create_file_tab(ac, av));
}
