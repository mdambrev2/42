/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_word_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 20:53:49 by mdambrev          #+#    #+#             */
/*   Updated: 2015/08/15 17:46:31 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			nb_word_str(char *str, char c)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!str)
		return (0);
	while (str[i] == c)
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i + 1] == c)
			i++;
		if (str[i] == c && str[i + 1] != '\0')
			y++;
		i++;
	}
	return (y + 1);
}
