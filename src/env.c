/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:32:48 by knakto            #+#    #+#             */
/*   Updated: 2025/02/21 00:33:14 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/kml.h"

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

char	*ft_envget(char *name)
{
	char	*find;
	char	*res;
	int		i;

	if (!name)
		return (NULL);
	find = find_env(name);
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

void	ft_export(char	*content)
{
	char	**all;
	char	*name;
	char	*value;
	char	**env;

	env = envhead();
	if (!content || ft_find(content, '=') != 1 || !*env)
		return ;
	all = ft_split(content, '=');
	name = ft_strtrim(all[0], " \t\n");
	value = ft_strtrim(all[1], " \t\n");
	free_split(all);
	if (ft_find(name, '=') > 0)
	{
		value = "";
		to_null(&name, '=');
	}
	if (find_env(name) != NULL)
		ft_envupdate(name, value);
	else
		ft_envadd(name, value);
	free(name);
	free(value);
}
