/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:26:20 by grorban           #+#    #+#             */
/*   Updated: 2023/04/04 15:26:22 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	x;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen)
		len = 0;
	else if (start + len > slen)
		len = slen - start;
	copy = ft_calloc(1, len + 1);
	if (copy)
	{
		x = 0;
		while (x < len)
		{
			copy[x] = s[start + x];
			x++;
		}
		copy[len] = 0;
	}
	return (copy);
}
