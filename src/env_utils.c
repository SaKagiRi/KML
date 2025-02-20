/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knakto <knakto@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:35:16 by knakto            #+#    #+#             */
/*   Updated: 2025/02/21 00:57:37 by knakto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/kml.h"

static int	*isunset(void)
{
	static int	unset = 0;

	return (&unset);
}

char	**envhead(void)
{
	static char	*env = NULL;

	return (&env);
}

void	ft_envinit(void)
{
	char	**env;

	if (*isunset())
		return ;
	env = envhead();
	*env = ft_envcreate("USER", "knakto");
	*isunset() = 1;
}

void	ft_unset(void)
{
	if (*isunset())
	{
		free(*envhead());
		*isunset() = 0;
	}
}

void	ft_envput(void)
{
	char	*env;

	env = *envhead();
	while (*env)
	{
		if (*env == ';')
		{
			write(1, "\n", 1);
			env++;
		}
		if (!*env)
			break ;
		write(1, env, 1);
		env++;
	}
}
