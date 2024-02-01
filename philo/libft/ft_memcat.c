/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:48:21 by grorban           #+#    #+#             */
/*   Updated: 2023/04/13 15:48:22 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memcat(char *string, char *buf, int string_size, int buf_size)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (string_size + buf_size + 1));
	if (res)
	{
		i = 0;
		while (i < string_size)
		{
			res[i] = string[i];
			i++;
		}
		while (i < string_size + buf_size)
		{
			res[i] = buf[i - string_size];
			i++;
		}
		res[i] = '\0';
	}
	free(string);
	return (res);
}
