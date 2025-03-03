/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:45:33 by knakto            #+#    #+#             */
/*   Updated: 2025/03/03 22:45:40 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/kml.h"

t_list	**envhead(void)
{
	static t_list	*env = NULL;

	return (&env);
}

t_env	*ft_envcreate(char *key, char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	return (new);
}

t_list	*ft_envfind(char *key)
{
	t_list	*env;
	int		len;

	env = *envhead();
	len = ft_strlen(key);
	while (env)
	{
		if (!ft_strncmp(((t_env *)env->content)->key, key, len + 1))
			return (env);
		env = env->next;
	}
	return (NULL);
}

int	ft_envupdate(char *key, char *value)
{
	t_list	*env;

	if (!value)
		return (0);
	env = ft_envfind(key);
	if (env)
	{
		free(((t_env *)env->content)->value);
		((t_env *)env->content)->value = ft_strdup(value);
		return (1);
	}
	return (0);
}

char	*ft_envget(char *key)
{
	t_list	*env;

	env = ft_envfind(key);
	if (env && ((t_env *)env->content)->value)
		return (ft_strdup(((t_env *)env->content)->value));
	return (NULL);
}
