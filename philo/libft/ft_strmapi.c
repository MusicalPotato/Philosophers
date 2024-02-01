/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:02:09 by grorban           #+#    #+#             */
/*   Updated: 2023/04/04 16:02:09 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	size;

	if (!s || !f)
		return (0);
	size = ft_strlen(s);
	result = malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	size = 0;
	while (s[size])
	{
		result[size] = f(size, s[size]);
		size++;
	}
	result[size] = 0;
	return (result);
}
