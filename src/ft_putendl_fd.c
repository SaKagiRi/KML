/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 03:26:00 by knakto            #+#    #+#             */
/*   Updated: 2024/09/07 22:58:50 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kml.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return (-1);
	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (write(fd, s, i) + write(fd, "\n", 1));
}
