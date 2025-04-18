/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 03:24:52 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:21:13 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s || fd < 0)
		return (-1);
	i = 0;
	while (*(s + i))
		i++;
	return (write(fd, s, i));
}
