/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtradd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:17:15 by mdambrev          #+#    #+#             */
/*   Updated: 2018/03/23 18:41:31 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_putwstr(wchar_t *wstr, int aff)
{
	int				x;
	int				ret;

	x = 0;
	ret = 0;
	while (wstr[x])
	{
		if (aff == 1)
			ret = ret + ft_putwchar(wstr[x], aff);
		else
			ret = ret + ft_weight_char(wstr[x]);
		x++;
	}
	return (ret);
}

int					ft_wstrlen(wchar_t *wstr)
{
	int				x;

	x = 0;
	while (wstr[x])
	{
		x++;
	}
	return (x);
}

wchar_t				*ft_wstrdup(wchar_t *s)
{
	int				x;
	wchar_t			*strdup2;
	int				i;

	i = 0;
	if (!s)
		return (NULL);
	x = ft_wstrlen(s);
	if ((strdup2 = ft_wstrnew(sizeof(wchar_t) * (x + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		strdup2[i] = s[i];
		i++;
	}
	strdup2[i] = '\0';
	return (strdup2);
}

wchar_t				*ft_wstrjoin(wchar_t *s1, wchar_t *s2)
{
	wchar_t			*cpy;
	int				x;

	x = 0;
	if (!s1 || !s2)
		return (NULL);
	if ((cpy = (wchar_t*)ft_wstrnew(sizeof(wchar_t) *
			(ft_wstrlen(s1) + ft_wstrlen(s2) + 1)))
			== NULL)
		return (NULL);
	while (*s2 || (*s2 == '\0' && *s1))
	{
		if (*s1 != '\0')
			*cpy++ = *s1++;
		else
			*cpy++ = *s2++;
		x++;
	}
	*cpy = '\0';
	return (cpy - x);
}

wchar_t				*ft_wstrndup(wchar_t *str, int start, int end)
{
	wchar_t		*ret;
	int			x;
	int			secu;

	secu = ft_wstrlen(str);
	if (secu < start)
		ft_putstr("error ft_wstrndup \n");
	if (secu < end)
		end = secu;
	x = 0;
	ret = (wchar_t *)malloc(4 * (end - start + 1));
	while (start < end)
	{
		ret[x] = str[start];
		start++;
		x++;
	}
	ret[start] = '\0';
	return (ret);
}
