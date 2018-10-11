/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt_msg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:17:37 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 08:35:47 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		display_prompt_msg(void)
{
	char	*cwd;
	char	buff[4096 + 1];
	char	*parsed_cwd;

	cwd = getcwd(buff, 4096);
	parsed_cwd = analyze_home_path(cwd, 0);
	ft_putstr(parsed_cwd);
	free(parsed_cwd);
	ft_putstr(" \033[0m\033[35magama\033[0m\033[32m>>\033[0m ");
}
