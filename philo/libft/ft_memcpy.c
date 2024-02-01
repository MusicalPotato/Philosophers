/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:43:24 by grorban           #+#    #+#             */
/*   Updated: 2023/04/03 13:43:27 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;

	if (!(src || dst))
		return (0);
	x = 0;
	while (x < n)
	{
		((char *)dst)[x] = ((char *)src)[x];
		x++;
	}
	return (dst);
}
