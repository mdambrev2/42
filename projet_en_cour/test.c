/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdavid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 20:25:10 by fdavid            #+#    #+#             */
/*   Updated: 2018/04/23 18:56:17 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int					main(int ac, char **av)
{
	int				i;
	int				j;
	int				nb;
	int				len;
	int				intlen;
	char				*str;
	char				*itoa;

	if (ac != 3)
		return (0);
	len = (int)strlen(av[1]);
	nb = atoi(av[2]);
	i = 0;
	while (i < nb)
	{
		j = 0;
		if (i % 1000 == 0)
			ft_printf("%d...\n", i);
		intlen = (int)ft_intlen(i);
		itoa = ft_itoa(i);
		if (i > 20 && i % 42 < 20)
		{
			if ((str = (char *)realloc(str, len + intlen + 1)) == NULL)
			{
				ft_printf("fail realloc %d %d\n", i, len + intlen + 1);
				break ;
			}
		}
		else
		{
			if ((str = (char *)malloc(len + intlen + 1)) == NULL)
			{
				ft_printf("fail malloc %d %d\n", i, len + intlen + 1);
				break ;
			}
		}
		while (j < len)
		{
			str[j] = av[1][j];
			j++;
		}
		j = 0;
		while (j < intlen)
		{
			str[j + len] = itoa[j];
			j++;
		}
		free(itoa);
		str[j] = '\0';
		i++;
	}
	show_alloc_mem();
	return (0);
}
