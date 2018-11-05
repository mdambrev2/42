/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_server_instruction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:08:35 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/05 23:08:25 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		receive_server_instruction(int sock)
{
	char buf[1024];

	ft_bzero(buf, 1024);
	read(sock, buf, 1023);
	buf[1023] = '\0';
	printf("receive to server --> %s\n", buf);
	return(0);
}
