/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:50:18 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 18:50:25 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "digit.h"

long	ft_htol(const char *nptr)
{
	size_t		i;
	int			j;
	char		*hex;
	long		res;

	i = 0;
	res = 0;
	hex = "0123456789ABCDEF";
	while (ft_isspace(*(nptr + i)) == 1)
		i++;
	while (nptr[i])
	{
		j = 0;
		while (j <= 15 && nptr[i] != hex[j])
			j++;
		if (j <= 15)
			res = res * 16 + j;
		else
			break ;
		i++;
	}
	return (res);
}
