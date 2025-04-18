/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:51:48 by knakto            #+#    #+#             */
/*   Updated: 2025/04/04 21:11:01 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
void	ft_lstremove_if(t_list **list, void *data_ref,
			int (*cmp)(void *content, void *data_ref),
			void (*del)(void *content));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
void	ft_lstiter_if(t_list *list, void (*f)(void *), void *data_ref,
			int (*cmp)(void *contnet, void *data_ref));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_list_find(t_list *list, void *data_ref,
			int (*cmp)(void *content, void *data_ref));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstadd_back(t_list **lst, t_list *node);

#endif
