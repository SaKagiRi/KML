/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:39:46 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:21:13 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	if (!src || !dst)
		return (0);
	i = 0;
	len = 0;
	while (*(src + len))
		len++;
	if (size == 0)
		return (len);
	while (*(src + i) && size - 1 > i)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	dst[i] = '\0';
	return (len);
}
