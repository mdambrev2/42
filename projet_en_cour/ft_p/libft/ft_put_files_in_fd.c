/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd_in_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:31:15 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/22 21:26:38 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					put_fd_in_files(int fd, char *path_file)
{
	int				fd_out;
	char			*buf;
	int				n_octet;


	buf = (char*)malloc(sizeof(char) * (1024));
	fd_out = open(path_file, O_TRUNC | O_RDWR | O_CREAT , S_IRWXU);
	while((n_octet = read(fd, buf, 1024)))
		write(fd_out, buf,  n_octet);
	close(fd_out);
	return(0);
}
