/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:23:29 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 09:42:42 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			find_env_var(char *var)
{
	int		i;
	char	*tmp;

	i = -1;
	while (g_envv[++i])
	{
		tmp = ft_strjoinch(var, '=');
		if (ft_strstartswith(g_envv[i], tmp))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
	}
	return (i);
}
