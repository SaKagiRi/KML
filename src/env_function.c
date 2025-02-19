/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:41:15 by knakto            #+#    #+#             */
/*   Updated: 2025/02/19 15:41:19 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/kml.h"

void	add_env(char *name, char *value, char **env)
{
	char	*temp;
	char	*temp2;
	char	*env2;
	char	*env1;
	int		i;

	if (!name || !env || !value)
		return ;
	env1 = *env;
	env2 = create_env(name, value);
	temp2 = env2;
	temp = malloc(ft_strlen(env1) + ft_strlen(env2) + 1);
	if (!temp)
		return ;
	i = 0;
	while (*env1)
		*(temp + i++) = *env1++;
	while (*env2)
		*(temp + i++) = *env2++;
	*(temp + i) = '\0';
	free(*env);
	free(temp2);
	*env = temp;
}

char	*find_env(char	*name, char *env)
{
	int	i;

	while (*env)
	{
		i = 0;
		while (*(env + i) == *(name + i))
		{
			i++;
			if (name[i] == '\0' && env[i] == '=')
				return (env);
		}
		env++;
	}
	return (NULL);
}

char	*get_env(char *name, char *env)
{
	char	*find;
	char	*res;
	int		i;

	if (!name || !env)
		return (NULL);
	find = find_env(name, env);
	if (!find)
		return (NULL);
	i = 0;
	while (*(find + i) != '=')
		i++;
	i++;
	res = ft_strdup(find + i);
	i = 0;
	while (*(res + i) != ';')
		i++;
	while (*(res + i))
		*(res + i++) = '\0';
	return (res);
}

void	delete_env(char	*name, char **env)
{
	char	*find;
	int		i;
	int		j;

	if (!name || !env)
		return ;
	find = find_env(name, *env);
	if (!find)
		return ;
	i = 0;
	j = 0;
	while (*(find + i) != ';')
		i++;
	i++;
	while (*(find + i))
		*(find + j++) = *(find + i++);
	while (*(find + j))
		*(find + j++) = '\0';
}

void	update_env(char *name, char *value, char **env)
{
	char	*find;
	char	*temp;
	int		i;

	if (!name || !env)
		return ;
	find = find_env(name, *env);
	if (!find)
		return ;
	i = 0;
	while (*(find + i) != ';')
		i++;
	i++;
	temp = ft_strdup(find + i);
	i = 0;
	while (*(find + i))
		*(find + i++) = '\0';
	add_env(name, value, env);
	*env = fjoin(*env, temp);
	free(temp);
}
