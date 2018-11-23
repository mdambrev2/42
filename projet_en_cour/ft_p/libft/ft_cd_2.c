/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 06:46:18 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 06:52:49 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "includes/libft.h"

int	put_error(int error, char **pwd, char **absolute_path)
{
	if (error == -1)
		printf("Out Of Range\n");
	if (error == -2)
		printf("No such Directory\n");
	if (error == -3)
		printf("Unknown option\n");
	ft_strdel(pwd);
	ft_strdel(absolute_path);
	return (-1);
}
