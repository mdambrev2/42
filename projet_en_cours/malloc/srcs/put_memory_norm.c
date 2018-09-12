/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_memory_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 21:29:40 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:22:14 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int			put_address(t_chained *tmp2, t_addrzone *tmp1, int *total)
{
	int		y;

	y = 0;
	while (tmp2 && (tmp2 != (void*)tmp1))
	{
		if (tmp2->free == 0)
		{
			ft_putstr("\n");
			ft_put_hexa((uintmax_t)tmp2->data);
			ft_putstr(" - ");
			ft_put_hexa((uintmax_t)tmp2->data + (uintmax_t)tmp2->size);
			ft_putstr(" : ");
			ft_putnbr(tmp2->size);
			ft_putstr(" octets");
			*total += tmp2->size;
			y++;
		}
		tmp2 = tmp2->next;
	}
	return (y);
}

int			put_page(t_chained *tmp2, t_addrzone *tmp1, int *total)
{
	int		ret;

	ft_put_hexa((uintmax_t)tmp1);
	ft_putstr("\n");
	ret = put_address(tmp2, tmp1, total);
	ft_putstr("\n\nNumber of Allocations per Zone : ");
	ft_putnbr(tmp1->nb_malloc);
	ft_putstr("\n");
	return (ret);
}
