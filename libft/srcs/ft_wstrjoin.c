/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 04:27:59 by agama             #+#    #+#             */
/*   Updated: 2018/10/11 07:22:48 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrjoin(wchar_t *s1, wchar_t *s2)
{
	wchar_t	*s;
	int		i;

	if (!(s = (wchar_t *)malloc(sizeof(wchar_t) *
		(1 + ft_wstrlen((wchar_t *)s1) + ft_wstrlen((wchar_t *)s2)))))
		return (NULL);
	i = 0;
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = '\0';
	return (s);
}
