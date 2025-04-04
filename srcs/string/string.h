/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:06:28 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 19:16:30 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <unistd.h>
# include <stdlib.h>
# include "../memory/memory.h"

char	*fjoin(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**fsplit(char *s, char c);
char	**ft_split(const char *s, char c);
char	**free_split(char **alloc);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t len);

#endif
