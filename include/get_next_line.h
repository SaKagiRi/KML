/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:53:41 by knakto            #+#    #+#             */
/*   Updated: 2025/01/22 20:56:34 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_line
{
	char			*content;
	int				length;
	struct s_line	*next;
}					t_line;

char	*get_next_line(int fd);

t_line	*ft_lstnew(char *content);

t_line	*ft_lstlast(t_line *lst);

void	ft_lstadd_back(t_line **lst, t_line *lst_new);

void	ft_lstclear(t_line **lst, void (*del)(void *));

void	*ft_calloc(size_t nmemb, size_t size);

#endif
