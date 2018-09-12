/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:56:00 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/29 17:44:03 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

int 				main(int ac, char **av)
{
	char			**file_tab;
	int				x;
	
	x = 0;
	if((file_tab = check_args(ac, av)) == NULL)
		return(EXIT_FAILURE);

	while(file_tab[x] != 0)
	{
		map(file_tab[x], ac, 1);
		x++;
	}
	return(0);
}

