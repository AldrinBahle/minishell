/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:09:02 by agama             #+#    #+#             */
/*   Updated: 2018/10/11 07:10:48 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, char control)
{
	char	*mem;

	mem = ft_strjoin(s1, s2);
	if (control == 'L' || control == 'B')
		free(s1);
	if (control == 'R' || control == 'B')
		free(s2);
	return (mem);
}
