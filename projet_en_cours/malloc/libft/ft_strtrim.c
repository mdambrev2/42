/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 05:42:01 by mdambrev          #+#    #+#             */
/*   Updated: 2018/02/15 16:48:49 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*strim;
	int		x;
	int		y;

	y = 0;
	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s)
		s++;
	x = (int)ft_strlen(s);
	while (s[x - 1] == ' ' || s[x - 1] == '\n' || s[x - 1] == '\t')
		x--;
	if (x < 0)
		x = 0;
	if ((strim = (char*)ft_memalloc(sizeof(strim) * x + 1)) == NULL)
		return (NULL);
	while (x-- > 0 && ++y)
		*strim++ = *s++;
	*strim = '\0';
	return (strim - y);
}
