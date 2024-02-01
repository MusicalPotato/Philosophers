/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:43:43 by grorban           #+#    #+#             */
/*   Updated: 2023/04/04 14:43:44 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		x;
	int		size;
	char	*copy;

	x = 0;
	if (!s1)
		return (0);
	size = ft_strlen(s1);
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (0);
	while (x < size)
	{
		copy[x] = s1[x];
		x++;
	}
	copy[x] = 0;
	return (copy);
}
