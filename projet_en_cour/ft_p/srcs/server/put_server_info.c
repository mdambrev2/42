/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_server_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:09:55 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 06:08:39 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

int				put_new_connection(void)
{
	static int	x = 0;

	x++;
	printf("\n\033[1;33mClient Number %d : Connected\033[00m\n", x);
	return (x);
}

void			put_connection_lost(int client_number, int cs)
{
	printf("\n\033[1;33mClient Number %d : Disconnected\033[00m\n"
			, client_number);
	close(cs);
}

void			put_client_error(int cs, char *str, int n_client)
{
	printf("\n\033[1;31mError Client %d : \"%s\"", n_client, str);
	printf(" is not a server command\033[00m\n");
	swap_to_error(1);
	send_string(cs, "BAD CMD\n");
}

void			set_null(char **cmd, char **ret)
{
	*cmd = NULL;
	*ret = NULL;
}
