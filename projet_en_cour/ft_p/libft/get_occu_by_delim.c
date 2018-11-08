/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_occu_by_delim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:54:15 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/08 22:07:55 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnlen(char *str, char delim)
{
	int x;

	x = 0;
	while(str[x] != delim && str[x] != 0)
		x++;
	x++;
	return(x);
}

char		*dup_occu(char *str, int offset, char delim)
{
	int		end;

	end = 0;
	while(str[offset] == delim)
		offset++;
	end = offset + ft_strnlen(str + offset, delim) - 1;
	return(ft_strndup(str, offset, end));
}

char		*dup_occu_by_delim(char *str, char delim, int n_occu)
{
	int x;
	int cmp;

	x = 0;
	cmp = 0;
	if(str == NULL)
		return(NULL);
	while(str[x] == delim)
		x++;
	while(str[x] != 0)	
	{
		if(str[x] == delim)
		{
			while(str[x] == delim)
				x++;
			cmp++;
		}
		 if(cmp == n_occu)
			 return(dup_occu(str, x, delim));
		x++;
	}
	return(NULL);
}

char		*get_occu(char *str, int offset, char delim)
{
	while(str[offset] == delim)
		offset++;
	return(str + offset);
}

char		*get_occu_by_delim(char *str, char delim, int n_occu)
{
	int x;
	int cmp;

	x = 0;
	cmp = 0;
	if(str == NULL)
		return(NULL);
	while(str[x] == delim)
		x++;
	while(str[x] != 0)	
	{
		if(str[x] == delim)
		{
			while(str[x] == delim)
				x++;
			cmp++;
		}
		 if(cmp == n_occu)
			 return(get_occu(str, x, delim));
		x++;
	}
	return(NULL);
}
