/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:39:46 by grorban           #+#    #+#             */
/*   Updated: 2023/04/03 15:39:47 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	if (size > 0)
	{
		while (i + j < size - 1 && src[j])
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	if (i < size)
		dst[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
