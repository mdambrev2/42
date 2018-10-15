/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnews.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 03:37:33 by mdambrev          #+#    #+#             */
/*   Updated: 2018/02/15 15:03:30 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	unsigned int	counter;
	char			*news;

	counter = 0;
	if ((news = (char *)ft_memalloc(sizeof(news) * size + 1)) == NULL)
		return (NULL);
	while (counter <= size)
	{
		*(news + counter) = '\0';
		counter++;
	}
	return (news);
}
