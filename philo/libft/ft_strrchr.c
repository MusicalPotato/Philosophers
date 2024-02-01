/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:03:35 by grorban           #+#    #+#             */
/*   Updated: 2023/04/05 15:03:36 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;

	x = 0;
	if (!s)
		return (0);
	while (s[x])
		x++;
	while (x >= 0)
		if (s[x--] == (char)c)
			return ((char *)s + x + 1);
	return (0);
}