/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:49:52 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 18:50:09 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "digit.h"

long	ft_atol(const char *nptr)
{
	size_t		i;
	char		sign;
	long		res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(*(nptr + i)) == 1)
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= *(nptr + i) && *(nptr + i) <= '9')
		res = res * 10 + (*(nptr + i++) - '0');
	return (sign * (long)res);
}
