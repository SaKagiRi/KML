/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:58:44 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:44:30 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "digit.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		res;

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
	return (sign * res);
}
