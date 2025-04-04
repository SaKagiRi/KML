/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:13:42 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 18:59:46 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

static t_list	**get_t_list(void)
{
	static t_list	*ls;

	return (&ls);
}

void	ft_free(void)
{
	ft_lstclear(get_t_list(), free);
}

void	*ft_malloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
	{
		ft_free();
		write(2, "Error: ft_malloc allocation failed.\n", 36);
		exit(EXIT_FAILURE);
	}
	ft_lstadd_back(get_t_list(), ft_lstnew(ptr));
	return (ptr);
}
