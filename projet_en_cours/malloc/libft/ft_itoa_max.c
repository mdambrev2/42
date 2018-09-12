/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 04:31:24 by mdambrev          #+#    #+#             */
/*   Updated: 2018/03/26 19:47:49 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	nb_chiffre(long long int n)
{
	long long	int		x;

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

static	long long int	taille_base(long long int n)
{
	long long	int		x;

	x = 1;
	if (n < 0)
		n = -n;
	while (x * 10 <= n)
	{
		if (n > 1000000000000000000)
		{
			x = 1000000000000000000;
			break ;
		}
		x *= 10;
	}
	return (x);
}

char					*ft_itoa_max(void *z)
{
	char				*tab;
	long long int		x;
	long long int		i;
	long long int		n;

	x = 0;
	i = 0;
	n = (long long int)z;
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if ((tab = (char *)ft_memalloc(sizeof(char) * (nb_chiffre(n) + 1))) == NULL)
		return (0);
	i = taille_base(n);
	if (n < 0)
	{
		n = -n;
		tab[x++] = '-';
	}
	while (i >= 1)
	{
		tab[x++] = ((n / i) % 10) + 48;
		i /= 10;
	}
	tab[x] = '\0';
	return (tab);
}
