/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 10:18:07 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/01 20:32:37 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdup(t_list *list)
{
	t_list	*tmp_list;
	t_list	*tmp_cpy;
	t_list	*cpy;

	tmp_list = list;
	cpy = ft_lstnew(tmp_list->content, tmp_list->content_size);
	tmp_cpy = cpy;
	while (tmp_list->next != NULL)
	{
		tmp_list = tmp_list->next;
		tmp_cpy->next = ft_lstnew(tmp_list->content, tmp_list->content_size);
		tmp_cpy = tmp_cpy->next;
	}
	return (cpy);
}
