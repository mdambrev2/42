/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 15:09:47 by mdambrev          #+#    #+#             */
/*   Updated: 2018/03/26 18:50:32 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	world(const char *s, char c)
{
	int		x;

	x = 0;
	while (*s)
	{
		if ((*s != c && *(s + 1) == c) || ((*s != c) && (*(s + 1) == '\0')))
		{
			x++;
			while ((*s == c) && *s)
				s++;
		}
		if (*s != '\0')
			s++;
	}
	return (x);
}

static int	world_len(const char *s, char c)
{
	int		x;

	x = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c)
			break ;
		x++;
		s++;
	}
	return (x);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (s == NULL ||
	(tab = (char **)ft_memalloc(1 + (sizeof(char *)) * world(s, c))) == NULL)
		return (NULL);
	while (*s == c)
		s++;
	while (*s)
	{
		if ((tab[x] = (char*)ft_memalloc(1 + ((world_len(s, c))))) == NULL)
			return (NULL);
		y = 0;
		while (*s != c && *s != '\0')
			tab[x][y++] = *s++;
		tab[x++][y] = '\0';
		while (*s == c && *s != '\0')
			s++;
	}
	tab[x] = 0;
	return (tab);
}
