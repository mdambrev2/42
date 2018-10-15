/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:18:27 by mdambrev          #+#    #+#             */
/*   Updated: 2015/05/23 11:14:03 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	const	*ft_verif(char const *nptr, int *signe)
{
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
			|| *nptr == '\v' || *nptr == '\r' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
	{
		*signe = -*signe;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	return (nptr);
}

int						ft_atoi(const char *nptr)
{
	int					len;
	int					signe;
	long	double		x;

	x = 0.0;
	len = 0;
	signe = 1;
	nptr = ft_verif(nptr, &signe);
	while (*nptr >= '0' && *nptr <= '9')
	{
		len *= 10;
		len += *nptr - '0';
		x *= 10;
		x += *nptr - '0';
		nptr++;
	}
	x = x * signe;
	if (x > 9223372036854775807)
		return (-1);
	if (x < -9223372036854775807)
		return (0);
	return (len * signe);
}
