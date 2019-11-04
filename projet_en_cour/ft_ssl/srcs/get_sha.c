/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:00:45 by mdambrev          #+#    #+#             */
/*   Updated: 2019/10/02 15:11:27 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include <ft_printf.h>
/*
uint64_t	num_of_bits;
uint64_t	zero_bits;

num_of_bits = (*len) * 8;
zero_bits = 0;
while ((num_of_bits + 1 + zero_bits + 64) % 512)
	zero_bits++;
sha->data = ft_memalloc((*len) + 1 + (zero_bits / 8) + 8);
ft_memcpy(sha->data, input, (*len));
sha->data[(*len)] = 128;
num_of_bits = swap_endian64(num_of_bits);
ft_memcpy(sha->data + (*len) + (zero_bits / 8) + 1,
			&num_of_bits, 8);
(*len) += (1 + (zero_bits / 8) + 8);
*/
void		add_padding_sha(t_mess *infos, char *message)
{
	uint64_t len_bit;
	uint64_t size_bit;
	uint64_t size;

	len_bit = infos->len * 8;
	size_bit = 0;
	while((len_bit + 1 + size_bit + 64) % 512)
		size_bit++;
	size = size_bit / 8;
	infos->data = ft_memalloc(size);
	ft_bzero(infos->data, size);
	ft_memcpy(infos->data, message, infos->len);
	infos->data[infos->data_len] = 0x80;
	infos->data_len = size;
}

void		get_sha(char *message)
{
	t_mess infos;

	infos.message = message;
	infos.len = ft_strlen(message);
	set_hexa_tab_sha(&infos);
	set_const_tab_sha(&infos);
	add_padding_sha(&infos, message);
}
