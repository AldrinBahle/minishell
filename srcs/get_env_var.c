/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:47:41 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 09:51:45 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_env_var(char *var)
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
			return (ft_strchr(g_envv[i], '=') + 1);
		}
		free(tmp);
	}
	return (NULL);
}
