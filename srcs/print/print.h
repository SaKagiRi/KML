/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:01:06 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:06:16 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		pnf(const char *str, ...);

#endif
