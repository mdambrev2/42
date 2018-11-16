/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_server_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:09:55 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/16 07:12:26 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

int		put_new_connection(void)
{
	static int x = 0;

	x++;
	printf("\n\033[1;33mClient Number %d : Connected\033[00m\n", x);
	return(x);
}

void     put_connection_lost(int client_number)
{
	printf("\n\033[1;33mClient Number %d : Disconnected\033[00m\n", client_number);
}
