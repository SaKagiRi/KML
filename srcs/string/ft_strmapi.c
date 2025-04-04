/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 03:13:59 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:21:13 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (ft_strdup(""));
	len = 0;
	while (*(s + len))
		len++;
	str = ft_strdup(s);
	if (str == NULL)
		return (str);
	while (i < len)
	{
		*(str + i) = (*f)(i, *(s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
