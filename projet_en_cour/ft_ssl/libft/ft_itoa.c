/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 04:31:24 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/29 19:10:49 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_chiffre(int n)
{
	int		x;

	x = 0;
	if (n < 0)
	{
		n = -n;
		x = 1;
	}
	while (n >= 1)
	{
		n /= 10;
		x++;
	}
	return (x);
}

static	int	taille_base(int n)
{
	int		x;

	x = 1;
	if (n < 0)
		n = -n;
	while (x * 10 <= n)
	{
		if (n > 1000000000)
		{
			x = 1000000000;
			break ;
		}
		x *= 10;
	}
	return (x);
}

static char	*overflow(void)
{
	char	*overflow;

	if ((overflow = (char *)ft_memalloc(sizeof(char) * 12)) == NULL)
		return (NULL);
	overflow[0] = '-';
	overflow[1] = '2';
	overflow[2] = '1';
	overflow[3] = '4';
	overflow[4] = '7';
	overflow[5] = '4';
	overflow[6] = '8';
	overflow[7] = '3';
	overflow[8] = '6';
	overflow[9] = '4';
	overflow[10] = '8';
	overflow[11] = '\0';
	return (overflow);
}

char		*ft_itoa(int n)
{
	char	*tab;
	int		x;
	int		i;

	x = 0;
	i = 0;
	if (n == -2147483648)
		return (overflow());
	if ((tab = (char *)ft_memalloc(sizeof(char) * (nb_chiffre(n) + 1))) == NULL)
		return (0);
	i = taille_base(n);
	if (n < 0)
	{
		n = -n;
		tab[x] = '-';
		x++;
	}
	while (i >= 1)
	{
		tab[x] = ((n / i) % 10) + 48;
		i /= 10;
		x++;
	}
	tab[x] = '\0';
	return (tab);
}
