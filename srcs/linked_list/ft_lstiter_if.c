/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:02:34 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:00:44 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstiter_if(t_list *list, void (*f)(void *), void *data_ref,
				int (*cmp)(void *contnet, void *data_ref))
{
	if (!list || !f || !data_ref || !cmp)
		return ;
	if (cmp(list->content, data_ref))
		f(list->content);
	ft_lstiter_if(list->next, f, data_ref, cmp);
}
