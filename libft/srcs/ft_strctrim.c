/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:23:48 by agama             #+#    #+#             */
/*   Updated: 2018/10/11 07:07:55 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	unsigned int	i;
	size_t			len;
	char			*mem;

	i = 0;
	while ((s[i]) == c)
		++i;
	len = ft_strlen(s) - 1;
	while (len > i && s[len] == c)
		len--;
	if (len < i)
		return (mem = ft_strdup(""));
	return (mem = ft_strsub(s, i, len - (size_t)i + 1));
}
