/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:43:40 by knakto            #+#    #+#             */
/*   Updated: 2025/04/06 06:41:09 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIGIT_H
# define DIGIT_H

# include <unistd.h>
# include "../character/character.h"

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
long	ft_htol(const char *nptr);

#endif
