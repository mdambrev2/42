/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_exist_in_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:36:25 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 07:37:09 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char		*if_exist_in_tab(char **tab, char *str)
{
	int		x;

	x = 0;
	if (str == NULL)
		return (NULL);
	while (tab[x] != 0)
	{
		if (ft_strcmp(tab[x], str) == 0)
			return (ft_strdup(tab[x]));
		x++;
	}
	return (NULL);
}
