/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:17:36 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/26 16:22:07 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char 	*get_str_end(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (str + x);
}
