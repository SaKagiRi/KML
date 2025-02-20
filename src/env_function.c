/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:34:26 by knakto            #+#    #+#             */
/*   Updated: 2025/02/21 00:34:49 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/kml.h"

char	*find_env(char	*name)
{
	int		i;
	char	*env;

	env = *envhead();
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

char	*ft_envcreate(char *name, char *value)
{
	char	*env;
	int		i;
	int		len_name;
	int		len_value;

	if (!name || !value)
		return (NULL);
	len_name = 0;
	len_value = 0;
	while (*(name + len_name))
		len_name++;
	while (*(value + len_value))
		len_value++;
	env = malloc(len_name + len_value + 3);
	if (!env)
		return (NULL);
	i = 0;
	while (*name)
		*(env + i++) = *name++;
	*(env + i++) = '=';
	while (*value)
		*(env + i++) = *value++;
	*(env + i++) = ';';
	*(env + i) = '\0';
	return (env);
}

void	ft_envadd(char *name, char *value)
{
	char	*temp;
	char	*temp2;
	char	*env2;
	char	**env;
	int		i;

	if (!name || !value)
		return ;
	env = envhead();
	env2 = ft_envcreate(name, value);
	temp2 = env2;
	temp = malloc(ft_strlen(*env) + ft_strlen(env2) + 1);
	if (!temp)
		return ;
	i = -1;
	while (env[0][++i])
		*(temp + i) = env[0][i];
	while (*env2)
		*(temp + i++) = *env2++;
	*(temp + i) = '\0';
	free(*env);
	free(temp2);
	*env = temp;
}

void	ft_envupdate(char *name, char *value)
{
	char	*find;
	char	*temp;
	char	**env;
	int		i;

	env = envhead();
	if (!name || !env)
		return ;
	find = find_env(name);
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
	ft_envadd(name, value);
	*env = fjoin(*env, temp);
	free(temp);
}

void	ft_envdelete(char	*name)
{
	char	*find;
	int		i;
	int		j;

	if (!name)
		return ;
	find = find_env(name);
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
