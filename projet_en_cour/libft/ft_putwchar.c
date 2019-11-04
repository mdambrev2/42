/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 12:33:22 by mdambrev          #+#    #+#             */
/*   Updated: 2018/03/26 19:05:03 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"
#include <wchar.h>

static void			write_2octet(wchar_t c, int aff)
{
	unsigned char	r1;
	unsigned char	r2;

	r1 = (unsigned char)c;
	r1 = r1 << 2;
	r1 = r1 >> 2;
	r1 = r1 | 128;
	c = c >> 6;
	r2 = (unsigned char)c;
	r2 = r2 << 3;
	r2 = r2 >> 3;
	r2 = r2 | 192;
	if (aff)
	{
		write(1, &r2, 1);
		write(1, &r1, 1);
	}
}

static void			write_3octet(wchar_t c, int aff)
{
	unsigned char	r1;
	unsigned char	r2;
	unsigned char	r3;

	r1 = (unsigned char)c;
	r1 = r1 << 2;
	r1 = r1 >> 2;
	r1 = r1 | 128;
	c = c >> 6;
	r2 = (unsigned char)c;
	r2 = r2 << 2;
	r2 = r2 >> 2;
	r2 = r2 | 128;
	c = c >> 6;
	r3 = (unsigned char)c;
	r3 = r3 << 4;
	r3 = r3 >> 4;
	r3 = r3 | 224;
	if (aff)
	{
		write(1, &r3, 1);
		write(1, &r2, 1);
		write(1, &r1, 1);
	}
}

static void			write_4octetbis(unsigned char r1, unsigned char r2,
		unsigned char r3, unsigned char r4)
{
	write(1, &r4, 1);
	write(1, &r3, 1);
	write(1, &r2, 1);
	write(1, &r1, 1);
}

static void			write_4octet(wchar_t c, int aff)
{
	unsigned char	r1;
	unsigned char	r2;
	unsigned char	r3;
	unsigned char	r4;

	r1 = (unsigned char)c;
	r1 = r1 << 2;
	r1 = r1 >> 2;
	r1 = r1 | 128;
	c = c >> 6;
	r2 = (unsigned char)c;
	r2 = r2 << 2;
	r2 = r2 >> 2;
	r2 = r2 | 128;
	c = c >> 6;
	r3 = (unsigned char)c;
	r3 = r3 << 2;
	r3 = r3 >> 2;
	r3 = r3 | 128;
	c = c >> 6;
	r4 = (unsigned char)c;
	r4 = r4 << 5;
	r4 = r4 >> 5;
	r4 = r4 | 240;
	write_4octetbis(r1, r2, r3, r4);
}

int					ft_putwchar(wchar_t c, int aff)
{
	int				x;

	if (c <= 127)
	{
		if (aff)
			write(1, &c, 1);
		x = 1;
	}
	else if (c <= 2047)
	{
		write_2octet(c, aff);
		x = 2;
	}
	else if (c <= 65535)
	{
		write_3octet(c, aff);
		x = 3;
	}
	else
	{
		if (aff)
			write_4octet(c, aff);
		x = 4;
	}
	return (x);
}
