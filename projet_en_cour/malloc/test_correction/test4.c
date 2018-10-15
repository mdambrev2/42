/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:45:36 by mdambrev          #+#    #+#             */
/*   Updated: 2018/05/09 16:45:51 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"
#include <string.h>
#include <unistd.h>

void			print(char *s)
{
	write(1, s, strlen(s));
}

int				main(void)
{
	char		*addr;

	addr = (char *)malloc(16);
	free(NULL);
	free((void *)addr + 5);
	if (realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
	return (0);
}
