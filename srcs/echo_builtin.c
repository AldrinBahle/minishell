/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:18:21 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 08:40:40 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	echo_out(char **str, int pos)
{
	int		starts_with;
	int		ends_with;
	int		str_len;

	starts_with = IS_QUOTE(str[pos][0]);
	str_len = (int)ft_strlen(str[pos]);
	ends_with = IS_QUOTE(str[pos][str_len - 1]);
	if (ends_with && starts_with)
		ft_putstrn(str[pos] + 1, -1);
	else if (ends_with)
		ft_putstrn(str[pos], -1);
	else if (starts_with)
		ft_putstr(str[pos] + 1);
	else
		ft_putstr(str[pos]);
	if (str[pos + 1])
		ft_putchar(' ');
}

int			echo_builtin(char **args)
{
	int		i;
	int		n_flag;

	n_flag = 0;
	if (!args[0])
	{
		ft_putchar('\n');
		return (1);
	}
	else if (args[0][0] == '-' && args[0][1] == 'n' && args[0][2] == '\0')
		n_flag = 1;
	i = -1;
	if (n_flag)
		++i;
	while (args[++i])
	{
		echo_out(args, i);
		if (!args[i + 1] && !n_flag)
			ft_putchar('\n');
	}
	return (1);
}
