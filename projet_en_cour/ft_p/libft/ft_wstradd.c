/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:54:08 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 06:57:31 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int					ft_weight_char(wchar_t s)
{
	if (s <= 127)
	{
		return (1);
	}
	else if (s <= 2047)
	{
		return (2);
	}
	else if (s <= 65535)
	{
		return (3);
	}
	else
	{
		return (4);
	}
}

int					ft_weight_wstrchar(wchar_t *s)
{
	int				x;
	int				ret;

	x = 0;
	ret = 0;
	while (s[x])
	{
		if (s[x] <= 127)
			ret = ret + 1;
		else if (s[x] <= 2047)
			ret = ret + 2;
		else if (s[x] <= 65535)
			ret = ret + 3;
		else
			ret = ret + 4;
		x++;
	}
	return (ret);
}

static int			wcmpbit(wchar_t *s, unsigned int start, size_t len)
{
	int				cpt;
	int				x;
	int				ret;

	x = 0;
	cpt = 0;
	ret = 0;
	while (start < len)
	{
		x = x + ft_weight_char(s[start]);
		if ((size_t)x > len)
			break ;
		start++;
		ret++;
	}
	return (ret);
}

wchar_t				*ft_wstrsub(wchar_t *s, unsigned int start, size_t len)
{
	wchar_t			*fresh;
	unsigned int	counter;
	int				x;
	int				y;

	x = 0;
	y = 0;
	counter = 0;
	y = wcmpbit(s, start, len);
	if ((fresh = ft_wstrnew(sizeof(wchar_t) * (y + 1))) == NULL)
		return (NULL);
	if (!s)
		return (NULL);
	ft_memcpy(fresh, s, y * 4);
	return (fresh);
}

wchar_t				*ft_wstrnew(size_t size)
{
	unsigned int	counter;
	wchar_t			*news;

	counter = 0;
	if ((news = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(news, sizeof(wchar_t) * (size + 1));
	return (news);
}
