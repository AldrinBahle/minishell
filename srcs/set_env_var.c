/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:50:53 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 11:29:18 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		set_env_var(char *key, char *value)
{
	int		pos;
	char	*tmp;

	pos = find_env_var(key);
	tmp = ft_strjoin("=", value);
	if (g_envv[pos])
	{
		free(g_envv[pos]);
		if (value)
			g_envv[pos] = ft_strjoin(key, tmp);
		else
			g_envv[pos] = ft_strjoin(key, "=");
	}
	else
	{
		g_envv = realloc_envv(pos + 1);
		if (value)
			g_envv[pos] = ft_strjoin(key, tmp);
		else
			g_envv[pos] = ft_strjoin(key, "=");
	}
	free(tmp);
}
