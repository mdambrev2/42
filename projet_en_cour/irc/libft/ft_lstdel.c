/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 09:02:35 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/04 05:01:15 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!del || !alst || !*alst)
		return ;
	tmp = (*alst);
	while (tmp != NULL)
	{
		del(tmp->content, tmp->content_size);
		tmp2 = tmp->next;
		free(tmp);
		tmp->next = NULL;
		tmp = tmp2;
	}
	*alst = NULL;
}
