/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brminner <brminner@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:09:08 by grorban           #+#    #+#             */
/*   Updated: 2023/10/19 13:50:23 by brminner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	x;

	x = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n < 1)
		return (0);
	while (s1[x] && s2[x] && x < n - 1 && s1[x] == s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
