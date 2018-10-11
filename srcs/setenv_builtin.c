/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:53:59 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 11:14:19 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	setenv_builtin(char **args)
{
	if (!args[0])
	{
		print_env();
		return (1);
	}
	if (args[1])
	{
		if (args[2])
		{
			ft_putendl("setenv: Too many arguments.");
			return (1);
		}
	}
	set_env_var(args[0], args[1]);
	return (1);
}
