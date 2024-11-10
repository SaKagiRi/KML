/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:29:15 by knakto            #+#    #+#             */
/*   Updated: 2024/08/24 15:38:26 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kml.h"

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1024);
	else
		return (0);
}
