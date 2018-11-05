/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_server_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:09:55 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/29 20:45:42 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

int		put_new_connection(void)
{
	static int x = 0;

	x++;
	printf("Client Number %d : Connected\n", x);
	return(x);
}

void     put_connection_lost(int client_number)
{
	printf("Client Number %d : Disconnected\n", client_number);
}
