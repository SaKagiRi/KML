/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:40:37 by knakto            #+#    #+#             */
/*   Updated: 2025/02/19 15:40:59 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/kml.h"

void	print_env(char *env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i] == ';')
		{
			write(1, "\n", 1);
			i++;
		}
		if (!env[i])
			break ;
		write(1, &env[i++], 1);
	}
}

char	*create_env(char *name, char *value)
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

static int	ft_find(char *str, char c)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (*(str + i++))
		if (*(str + i) == c)
			status += 1;
	return (status);
}

static void	to_null(char **str, char c)
{
	int	i;

	i = 0;
	while (*(*str + i))
	{
		if (*(*str + i) == c)
			*(*str + i) = '\0';
		i++;
	}
}

void	ft_export(char	*content, char **env)
{
	char	**all;
	char	*name;
	char	*value;

	if (!content || !env)
		return ;
	if (ft_find(content, '=') != 1)
		return ;
	if (!*env)
		*env = create_env("USER", "knakto");
	all = ft_split(content, '=');
	name = all[0];
	value = all[1];
	if (ft_find(name, '=') > 0)
	{
		value = "";
		to_null(&name, '=');
	}
	if (find_env(name, *env) != NULL)
		update_env(name, value, env);
	else
		add_env(name, value, env);
	free_split(all);
}
