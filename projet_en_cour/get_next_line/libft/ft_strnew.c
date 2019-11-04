/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnews.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 03:37:33 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/15 20:04:23 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	unsigned int	counter;
	char			*news;

	counter = 0;
	if ((news = (char *)malloc(sizeof(news) * size + 1)) == NULL)
		return (NULL);
	while (counter <= size)
	{
		*(news + counter) = '\0';
		counter++;
	}
	return (news);
}
