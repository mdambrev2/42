/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:15:23 by mdambrev          #+#    #+#             */
/*   Updated: 2019/04/04 19:21:35 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

void							otool_put_name_norm(char *name, int ar)
{
	if (ar == 0 || ar == 5)
		ft_printf("%s:\nContents of (__TEXT,__text) section\n", name);
	else
		ft_printf("Contents of (__TEXT,__text) section\n", name);
}

uint32_t						put_addres_otool_32(uint32_t addr)
{
	char						*str1;

	str1 = ft_convert_base_max((uint64_t)addr, 16);
	str1 = add_octet_otool_32(str1, ft_strlen(str1), 8);
	ft_printf("%s\t", str1);
	free(str1);
	addr = addr + 16;
	return (addr);
}

void							arm(uint64_t cpt, uint32_t *addr, char *str)
{
	char						*str1;
	static	char				ret[9];
	static	int					x = 0;

	ret[8] = '0';
	if (cpt % 16 == 0 || cpt == 0)
		*addr = put_addres_otool_32(*addr);
	str1 = ft_convertn_base_max(str[cpt], 16, 2);
	ret[x] = str1[0];
	ret[x + 1] = str1[1];
	x += 2;
	if ((cpt + 1) % 4 == 0)
	{
		x = 7;
		while (x >= 0)
		{
			ft_putchar(ret[x - 1]);
			ft_putchar(ret[x]);
			x -= 2;
		}
		ft_printf(" ", ret);
		x = 0;
	}
	free(str1);
}

uint64_t						put_addres_otool(uint64_t addr)
{
	char						*str1;

	str1 = ft_convert_base_max((uintmax_t)addr, 16);
	str1 = add_octet_otool_32(str1, ft_strlen(str1), 16);
	ft_printf("%s\t", str1);
	free(str1);
	addr = addr + 16;
	return (addr);
}
