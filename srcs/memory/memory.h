/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:56:50 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:04:34 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "../linked_list/linked_list.h"

void	ft_free(void);
void	*ft_malloc(size_t count, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
