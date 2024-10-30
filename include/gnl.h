/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 04:39:34 by knakto            #+#    #+#             */
/*   Updated: 2024/10/30 15:51:05 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# ifndef LIMIT
#  define LIMIT 10000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_lst
{
	char			content[BUFFER_SIZE];
	size_t			len;
	struct s_lst	*next;
}	t_lst;

typedef struct s_var
{
	int		fd;
	int		eof;
	int		fin;
	t_lst	*word;
	t_lst	*run;
	size_t	offset;
	size_t	nlb;
}	t_var;

void	set_line(t_var *var);
void	coppy_line(t_var *var, char *str);
void	read_line(t_var *var);
void	set_start(t_var *var, int fd);
char	*get_next_line(int fd);

#endif
