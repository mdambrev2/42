/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 09:11:00 by mdambrev          #+#    #+#             */
/*   Updated: 2018/10/08 09:43:56 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm_otool.h>

int						map(char *str, int ac, int set)
{
	struct stat			buf;
	void				*ptr;
	int					fd;

	if ((fd = open(str, O_RDONLY)) < 0)
		return (put_open_args_fail(str));
	fstat(fd, &buf);
	if (S_ISDIR(buf.st_mode) == 1)
		return (put_buff_error(str));
	ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (set == 0 && ac <= 2)
		fd = nm(ptr, str, 0, &buf);
	else if (set == 0 && ac > 2)
		fd = nm(ptr, str, 5, &buf);
	else if (set == 1 && ac <= 2)
		fd = otool(ptr, str, 0, &buf);
	else if (set == 1 && ac > 2)
		fd = otool(ptr, str, 5, &buf);
	munmap(ptr, buf.st_size);
	return (fd);
}

void					put_list(t_circ *ret, char *name, int ac)
{
	ret = ret->racine->next;
	if (ac > 2 && ac != 5)
		ft_printf("\n%s\n", name);
	else if (ac == 5)
		ft_printf("\n%s:\n", name);
	if (ret->type == 'T' && ret->value[0] == '_')
	{
		ft_memdel((void*)&ret->value);
		ft_memdel((void*)&ret->function_name);
	}
	while (ret != ret->racine)
	{
		ft_printf("%s %c %s\n", ret->value, ret->type, ret->function_name);
		ft_memdel((void*)&ret->value);
		ft_memdel((void*)&ret->function_name);
		ret = ret->next;
	}
	free_circ(ret->racine);
}
