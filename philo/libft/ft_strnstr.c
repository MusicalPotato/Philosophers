/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:19:08 by grorban           #+#    #+#             */
/*   Updated: 2023/04/04 13:19:09 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle && *needle)
	{
		while (i < len && haystack[i])
		{
			j = 0;
			while (haystack[i + j] && needle[j]
				&& haystack[i + j] == needle[j] && i + j < len)
			{
				j++;
				if (!needle[j])
					return ((char *)haystack + i);
			}
			i++;
		}
		return (0);
	}
	return ((char *)haystack);
}
