/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:40:53 by mdambrev          #+#    #+#             */
/*   Updated: 2019/08/12 14:51:18 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void	print_prompt(t_env *e)
{
	ft_putstr("<");
	ft_putstr(e->fds[e->sock].name);
	ft_putstr("> ");
}

void	clean_prompt(t_env *e)
{
	int i;
	int	len;

	i = 0;
	(void)e;
	len = ft_strlen(e->fds[e->sock].name);
	ft_putchar(' ');
	ft_putchar(' ');
	while (i < 100)
	{
		ft_putchar('\b');
		ft_putchar(' ');
		ft_putchar('\b');
		i++;
	}
}
