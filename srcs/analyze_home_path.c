/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_home_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:16:46 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 08:21:34 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*analyze_home_path(char *path, int reverse_parse)
{
	char	*home_path;
	char	*new;

	if (!path)
		return (NULL);
	home_path = get_env_var("HOME");
	if (!ft_strstartswith(path, reverse_parse ? "~" : home_path))
		return (ft_strdup(path));
	if (reverse_parse)
		new = ft_pathjoin(home_path, path + 1);
	else
	{
		if (*(path + ft_strlen(home_path)) == '\0')
			new = ft_strdup("~");
		else
			new = ft_pathjoin("~", path + ft_strlen(home_path));
	}
	return (new);
}
