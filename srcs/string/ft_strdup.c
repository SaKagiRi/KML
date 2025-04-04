/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:21:58 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:21:13 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dest;

	if (!s1)
		return (NULL);
	i = 0;
	while (*(s1 + i))
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i) && dest != NULL)
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
