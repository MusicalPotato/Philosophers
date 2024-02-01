/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:35:51 by grorban           #+#    #+#             */
/*   Updated: 2023/04/04 15:35:52 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrim(char c, char const *set)
{
	while (*set != 0)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_lentrim(char const *s1, char const *set, int len)
{
	while (ft_istrim(s1[len - 1], set))
		len--;
	while (ft_istrim(*s1, set))
	{
		len--;
		s1++;
	}
	if (len < 0)
		return (0);
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;
	int		x;

	x = 0;
	if (!s1 || !set)
		return (0);
	size = ft_lentrim(s1, set, ft_strlen(s1));
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	while (ft_istrim(s1[x], set))
		x++;
	str[size] = 0;
	while (size--)
		str[size] = s1[size + x];
	return (str);
}
