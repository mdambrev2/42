/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:50:32 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/01 20:28:27 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void			*slot;
	char			*init;
	unsigned int	counter;

	slot = (void*)malloc(sizeof(slot) * size);
	init = (char*)slot;
	counter = 0;
	while (slot && counter <= size)
	{
		init[counter] = 0;
		counter++;
	}
	return (slot);
}
