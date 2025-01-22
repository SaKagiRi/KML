/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:58:44 by knakto            #+#    #+#             */
/*   Updated: 2024/09/03 22:29:15 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/kml.h"

static int	space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	while (space(*(nptr + i)) == 1)
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

long	ft_atol(const char *nptr)
{
	size_t		i;
	char		sign;
	long		res;

	i = 0;
	res = 0;
	sign = 1;
	while (space(*(nptr + i)) == 1)
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

long	ft_htol(const char *nptr)
{
	size_t		i;
	int			j;
	char		*hex;
	long		res;

	i = 0;
	res = 0;
	hex = "0123456789ABCDEF";
	while (space(*(nptr + i)) == 1)
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
