/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:05:03 by knakto            #+#    #+#             */
/*   Updated: 2025/01/25 16:05:03 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/kml.h"

void	ft_lstremove_if(t_list **list, void *data_ref,
		int (*cmp)(void *content, void *data_ref), void (*del)(void *content))
{
	t_list	*node;

	if (!list || !*list || !(*list)->next || !data_ref || !cmp || !del)
		return ;
	if (cmp((*list)->content, data_ref))
	{
		node = *list;
		*list = (*list)->next;
		del(node->content);
		free(node);
	}
	while ((*list)->next)
	{
		if (cmp((*list)->next->content, data_ref))
		{
			node = (*list)->next;
			(*list)->next = node->next;
			del(node->content);
			free(node);
		}
	}
}
