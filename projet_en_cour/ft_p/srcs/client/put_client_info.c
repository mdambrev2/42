/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_server_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:09:55 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/06 21:55:53 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

int		put_client_connection(int cs)
{
	t_message   msg;
	char        *buf;
	
	msg.messagetype = 0;
	while(receive(cs, &msg) == 1)
	{
		buf = read_data(cs, msg);
		printf("Client Number %s : Connected\n", buf);
	}
	return(0);
}
