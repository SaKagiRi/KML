/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:12:18 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:00:44 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list	*ft_list_find(t_list *list, void *data_ref,
					int (*cmp)(void *content, void *data_ref))
{
	if (!list || !data_ref || !cmp)
		return (NULL);
	if (cmp(list->content, data_ref))
		return (list);
	return (ft_list_find(list->next, data_ref, cmp));
}
