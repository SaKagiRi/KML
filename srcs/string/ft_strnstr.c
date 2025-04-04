/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:56:47 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:21:13 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;

	if (*little == 0)
		return ((char *)big);
	i = 0;
	while (*(little + i))
		i++;
	while (*big != '\0' && i <= n)
	{
		if (*big == *little && ft_strncmp(big, little, i) == 0)
			return ((char *)big);
		big++;
		n--;
	}
	return (0);
}
