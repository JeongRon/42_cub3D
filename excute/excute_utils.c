/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:57:22 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/09 20:01:29 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_abs(double num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ndst;
	unsigned char	*nsrc;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	if (ndst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		i++;
	}
	return (ndst);
}
