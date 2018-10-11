/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_envv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:49:57 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 11:26:36 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**realloc_envv(int new_size)
{
	char	**new;
	int		i;

	new = (char **)ft_memalloc(sizeof(char *) * (new_size + 1));
	i = -1;
	while (g_envv[++i] && i < new_size)
	{
		new[i] = ft_strdup(g_envv[i]);
		free(g_envv[i]);
	}
	free(g_envv);
	return (new);
}
