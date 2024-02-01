/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:34:34 by grorban           #+#    #+#             */
/*   Updated: 2023/04/03 14:34:35 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			x;
	unsigned char	*dsttemp;
	unsigned char	*srctemp;

	if (dst == src)
		return (dst);
	dsttemp = (unsigned char *)dst;
	srctemp = (unsigned char *)src;
	x = 0;
	if (srctemp > dsttemp)
	{
		while (x < len)
		{
			dsttemp[x] = srctemp[x];
			x++;
		}
	}
	else
	{
		while (len-- > 0)
			dsttemp[len] = srctemp[len];
	}
	return (dst);
}
