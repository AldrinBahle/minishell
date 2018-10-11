/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:14:46 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 08:33:49 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_pth(char *path)
{
	char	*parsed_home;

	parsed_home = analyze_home_path(path, 0);
	ft_putstr(parsed_home);
	free(parsed_home);
}

void		change_dir(char *path, int print_path)
{
	char	*cwd;
	char	buff[4097];

	cwd = getcwd(buff, 4096);
	if (!chdir(path))
	{
		if (print_path)
		{
			print_pth(path);
			ft_putchar('\n');
		}
		set_env_var("OLDPWD", cwd);
	}
	else
	{
		ft_putstr("cd: ");
		if (access(path, F_OK) == -1)
			ft_putstr("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			ft_putstr("permission denied: ");
		else
			ft_putstr("not a directory: ");
		ft_putendl(path);
	}
}
