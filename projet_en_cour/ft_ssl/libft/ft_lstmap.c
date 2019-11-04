/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 14:52:15 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/01 20:30:52 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp_list;
	t_list	*tmp_ret;
	t_list	*tmp_ret2;

	if (lst == NULL)
		return (NULL);
	tmp_list = lst;
	tmp_ret = f(tmp_list);
	tmp_ret2 = tmp_ret;
	while (tmp_list->next != NULL)
	{
		tmp_list = tmp_list->next;
		tmp_ret->next = f(tmp_list);
		tmp_ret = tmp_ret->next;
	}
	return (tmp_ret2);
}
