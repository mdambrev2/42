/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:01:12 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/24 18:37:37 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/libft.h"

int main(void)
{
	char *str1;
	char *str2;
	char *start;
	
	start = malloc(1024);
	str1 = malloc(1024);
	str2 = malloc(1024);

	start = getcwd(start, 1024);

	str1 = getcwd(str1, 1024);
	str1 = ft_strjoin(str1, "/-");
	chdir(str1);
	
	str2 = getcwd(str2, 1024);
	if(ft_strstr(str2, start))
		printf("sucess\n");
	else
	{
		printf("error\n");
	}
	printf("%s %s\n", ft_strcut(str2, start), str2);
}
