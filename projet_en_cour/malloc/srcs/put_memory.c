/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:24:10 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:22:00 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void			ft_put_tiny(void)
{
	t_addrzone	*tmp1;
	t_chained	*tmp2;
	int			y;
	int			x;
	int			total;

	y = 0;
	x = 1;
	tmp1 = g_zone.t_zone;
	total = 0;
	while (tmp1)
	{
		ft_putstr("\n\n\nTINY : Zone ");
		ft_putnbr(x++);
		ft_putstr("\n\nAdress Zone : ");
		tmp2 = tmp1->next;
		y += put_page(tmp2, tmp1, &total);
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.t_zone)
			break ;
	}
	ft_putstr("\n\nTotal TINY Allocations : ");
	ft_putnbr(y);
	ft_putstr("\n\nTotal TINY octets : ");
	ft_putnbr(total);
}

void			ft_put_small(void)
{
	t_addrzone	*tmp1;
	t_chained	*tmp2;
	int			y;
	int			x;
	int			total;

	y = 0;
	x = 1;
	tmp1 = g_zone.s_zone;
	total = 0;
	while (tmp1)
	{
		ft_putstr("\n\n\n\n\nSMALL : Zone ");
		ft_putnbr(x++);
		ft_putstr("\n\nAdress Zone : ");
		tmp2 = tmp1->next;
		y += put_page(tmp2, tmp1, &total);
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.s_zone)
			break ;
	}
	ft_putstr("\n\nTotal SMALL Allocations : ");
	ft_putnbr(y);
	ft_putstr("\n\nTotal SMALL octets : ");
	ft_putnbr(total);
}

void			put_zone(t_addrzone *tmp1, int x)
{
	ft_putstr("\n\n\n\n\nLARGE : ZONE ");
	ft_putnbr(x);
	ft_putstr("\n\nAdress page : ");
	ft_put_hexa((uintmax_t)tmp1);
	ft_putstr("\n\n");
	ft_put_hexa((uintmax_t)tmp1->data);
	ft_putstr(" - ");
	ft_put_hexa((uintmax_t)tmp1->data + (uintmax_t)tmp1->size);
	ft_putstr(" : ");
	ft_putnbr(tmp1->size);
}

int				ft_put_large(void)
{
	t_addrzone	*tmp1;
	int			y;
	int			x;
	int			total;

	y = 0;
	x = 1;
	total = 0;
	tmp1 = g_zone.l_zone;
	while (tmp1)
	{
		put_zone(tmp1, x);
		y++;
		x++;
		total += tmp1->size;
		tmp1 = tmp1->zone_next;
		if (tmp1 == g_zone.l_zone)
			break ;
	}
	ft_putstr("\n\n\nTotal LARGE Allocations : ");
	ft_putnbr(y);
	ft_putstr("\n\nTotal LARGE octets : ");
	ft_putnbr(total);
	ft_putstr(" octets\n\n\n\n");
	return (0);
}

void			show_alloc_mem(void)
{
	pthread_mutex_lock(&g_malloc_lock);
	if (g_zone.t_zone != NULL)
	{
		ft_put_tiny();
	}
	if (g_zone.s_zone != NULL)
	{
		ft_put_small();
	}
	if (g_zone.l_zone != NULL)
	{
		ft_put_large();
	}
	pthread_mutex_unlock(&g_malloc_lock);
}
