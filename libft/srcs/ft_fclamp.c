/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 06:12:13 by agama             #+#    #+#             */
/*   Updated: 2018/10/09 16:29:42 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_fclamp(float n, float min, float max)
{
	if (n < min)
		return (min);
	return (n > max ? max : n);
}
