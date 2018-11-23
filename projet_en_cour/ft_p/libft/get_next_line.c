/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:02:57 by mdambrev          #+#    #+#             */
/*   Updated: 2018/11/23 07:35:01 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static char			*mjoin(char *a, char *b)
{
	char			*result;

	if (!a)
		return (ft_strdup(b));
	result = ft_strjoin(a, b);
	free(a);
	return (result);
}

static int			check(char **str, char *line)
{
	int				x;
	char			*tmp;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == '\n')
		{
			line[x] = '\0';
			tmp = *str;
			*str = mjoin(*str, &line[x + 1]);
			ft_strdel(&tmp);
			return (-1);
		}
		x++;
	}
	return (0);
}

int					norm_get_next_line(int fd, char **buf,
										int *ret, char **line)
{
	char *tmp;

	tmp = *buf;
	if ((*ret = read(fd, *buf, BUFF_SIZE)) == -1)
	{
		ft_strdel(buf);
		return (-1);
	}
	tmp[*ret] = '\0';
	if (ret == 0)
	{
		ft_strdel(buf);
		return (ft_strlen(*line) > 0);
	}
	return (5);
}

int					get_next_line(int const fd, char **line)
{
	int				ret;
	static char		*str = 0;
	char			*buf;
	char			*tmp;
	int				ret2;

	if (!line)
		return (-1);
	if ((buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	tmp = ft_strnew(0);
	*line = mjoin(str, tmp);
	free(tmp);
	str = 0;
	while (check(&str, *line) != -1)
	{
		if ((ret2 = norm_get_next_line(fd, &buf, &ret, line)) != 5)
			return (ret2);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		ft_strdel(&tmp);
	}
	ft_strdel(&buf);
	return (1);
}
