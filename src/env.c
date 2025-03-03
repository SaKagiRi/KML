/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:46:00 by knakto            #+#    #+#             */
/*   Updated: 2025/03/03 22:48:29 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/kml.h"

void	ft_envput(void)
{
	t_list	*env;

	env = *envhead();
	while (env)
	{
		pnf("%s=%s\n", \
			((t_env *)env->content)->key, ((t_env *)env->content)->value);
		env = env->next;
	}
}

void	ft_envadd(char *key, char *value)
{
	t_list	**env;
	t_list	*new;

	if (ft_envupdate(key, value) || !value)
		return ;
	env = envhead();
	new = ft_lstnew(ft_envcreate(key, value));
	ft_lstadd_back(env, new);
}

void	f_free(void *content)
{
	free(((t_env *)content)->key);
	free(((t_env *)content)->value);
	free(content);
}

void	ft_unset(void)
{
	t_list	**env;

	env = envhead();
	ft_lstclear(env, f_free);
}

void	ft_envdel(char *key)
{
	t_list	*env;
	t_list	*node;

	env = *envhead();
	node = NULL;
	if (env && \
		!ft_strncmp(((t_env *)env->content)->key, key, ft_strlen(key) + 1))
	{
		node = env;
		*envhead() = env->next;
		ft_lstdelone(node, f_free);
		return ;
	}
	while (env)
	{
		if (env->next && !ft_strncmp(((t_env *)env->next->content)->key, \
				key, ft_strlen(key) + 1))
		{
			node = env->next;
			env->next = node->next;
			ft_lstdelone(node, f_free);
		}
		env = env->next;
	}
}
