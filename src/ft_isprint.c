/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:57:29 by knakto            #+#    #+#             */
/*   Updated: 2024/08/24 16:02:32 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/kml.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (16384);
	else
		return (0);
}
