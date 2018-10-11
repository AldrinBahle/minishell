/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:56:42 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 09:57:29 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	envv_len(char **envv)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (envv[++i])
		count++;
	return (count);
}

void		init_envv(int argc, char **argv, char **envv)
{
	int		i;

	(void)argc;
	(void)argv;
	g_envv = (char **)ft_memalloc(sizeof(char *) * (envv_len(envv) + 1));
	i = -1;
	while (envv[++i])
	{
		if (!(g_envv[i] = ft_strdup(envv[i])))
			exit_shell();
	}
}
