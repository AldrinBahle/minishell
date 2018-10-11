/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:35:13 by agama             #+#    #+#             */
/*   Updated: 2018/09/18 11:50:23 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrn(char *str, int n)
{
	int	i;

	i = -1;
	if (n < 0)
	{
		while (str[++i] && i < (int)ft_strlen(str) + n)
			ft_putchar(str[i]);
	}
	else
	{
		while (str[++i] && i < n)
			ft_putchar(str[i]);
	}
}
