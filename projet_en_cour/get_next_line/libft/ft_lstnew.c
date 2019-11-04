/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 05:32:25 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/01 20:29:46 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*cpy;

	if ((cpy = malloc(sizeof(unsigned char) * content_size)) == NULL)
		return (NULL);
	if ((list = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if ((cpy = malloc(sizeof(unsigned char) * content_size)) == NULL)
			return (NULL);
		ft_memcpy(cpy, content, content_size);
		list->content = malloc(sizeof(content) * content_size);
		list->content_size = content_size;
		list->content = cpy;
	}
	list->next = NULL;
	return (list);
}
