/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:15:36 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 08:29:44 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_two_args(char **args)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*tmp;

	if (args[1])
	{
		if (args[2])
		{
			ft_putendl("cd: too many arguments");
			return (1);
		}
		cwd = getcwd(buff, 4096);
		if (!(tmp = ft_strreplace(cwd, args[0], args[1])))
		{
			ft_putstr("cd: string not in pwd: ");
			ft_putendl(args[0]);
			free(tmp);
			return (1);
		}
		change_dir(tmp, 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int			cd_builtin(char **args)
{
	char	*home_path;

	home_path = get_env_var("HOME");
	if (!args[0])
	{
		change_dir(home_path, 0);
		return (1);
	}
	if (has_two_args(args))
		return (1);
	else
	{
		if (ft_strequ(args[0], "--"))
		{
			change_dir(home_path, 0);
			return (1);
		}
		else if (args[0][0] == '-' && !args[0][2])
		{
			change_dir(get_env_var("OLDPWD"), 1);
			return (1);
		}
		change_dir(args[0], 0);
	}
	return (1);
}
