/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_md5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:56:08 by mdambrev          #+#    #+#             */
/*   Updated: 2019/10/01 16:10:21 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

uint32_t    revers_uint32(uint32_t n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8) |
			((n & 0xff00) << 8) | (n << 24));
}

void	add_padding_message(t_mess *infos)
{
	infos->h[0] = 0x67452301;
	infos->h[1] = 0xEFCDAB89;
	infos->h[2] = 0x98BADCFE;
	infos->h[3] = 0x10325476;
	infos->data_len = infos->len + 1;
	while(infos->data_len % 64 != 56)
		infos->data_len++;
	infos->data = (unsigned char *)ft_strnew(infos->data_len + 64);
	ft_bzero(infos->data, infos->data_len + 64);
	ft_memcpy(infos->data, infos->message, infos->len);
	infos->data[infos->len] = (char)128;
	*(uint32_t*)(infos->data + infos->data_len) = (uint32_t)(8 * infos->len);
}



uint32_t	leftrotate(uint32_t x, uint32_t c)
{
	return (((x) << (c)) | ((x) >> (32 - (c))));
}

void		set_md5_var(t_mess *infos)
{
	if (infos->i < 16)
	{
		infos->f = (infos->b & infos->c) | ((~infos->b) & infos->d);
		infos->g = infos->i;
	}
	else if (infos->i < 32)
	{
		infos->f = (infos->d & infos->b) | ((~infos->d) & infos->c);
		infos->g = (5 * infos->i + 1) % 16;
	}
	else if (infos->i < 48)
	{
		infos->f = infos->b ^ infos->c ^ infos->d;
		infos->g = (3 * infos->i + 5) % 16;
	}
	else
	{
		infos->f = infos->c ^ (infos->b | (~infos->d));
		infos->g = (7 * infos->i) % 16;
	}
	infos->tmp = infos->d;
	infos->d = infos->c;
	infos->c = infos->b;
	infos->b = infos->b + leftrotate((infos->a + infos->f + infos->hexa[infos->i] + infos->w[infos->g]), infos->cons[infos->i]);;
	infos->a = infos->tmp;
}

void	handle_md5(t_mess *infos)
{
	int offset;

	offset = 0;
	while(offset < infos->data_len)
	{
		infos->w = (uint32_t *)(infos->data + offset);
		infos->a = infos->h[0];
		infos->b = infos->h[1];
		infos->c = infos->h[2];
		infos->d = infos->h[3];
		infos->i = 0;
		while(infos->i < 64)
		{
			set_md5_var(infos);	
			infos->i++;
		}
		infos->h[0] = infos->h[0] + infos->a;
		infos->h[1] = infos->h[1] + infos->b;
		infos->h[2] = infos->h[2] + infos->c;
		infos->h[3] = infos->h[3] + infos->d;
		offset += 64;
	}
	ft_printf("%x%x%x%x", revers_uint32(infos->h[0]), revers_uint32(infos->h[1]), revers_uint32(infos->h[2]), revers_uint32(infos->h[3]));
}

char	*get_md5(char *message, t_env *env)
{
	t_mess infos;
	
	if(env->sha == 1)
	{
		get_sha(message);
		return(NULL);
	}
	infos.message = message;
	infos.len = ft_strlen(message);
	set_const_tab(&infos);
	set_hexa_tab(&infos);
	add_padding_message(&infos);
	handle_md5(&infos);
	return(NULL);
}
