/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:04 by grorban           #+#    #+#             */
/*   Updated: 2023/10/20 14:46:05 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int n)
{
	char	*copy;
	int		size;

	size = 0;
	while (str && str[size] && size < n)
		size++;
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (0);
	size = 0;
	while (str && str[size] && size < n)
	{
		copy[size] = str[size];
		size++;
	}
	copy[size] = '\0';
	return (copy);
}
