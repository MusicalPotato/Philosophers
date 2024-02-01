/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:48:03 by grorban           #+#    #+#             */
/*   Updated: 2023/04/04 15:48:05 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**make_list(const char *str, char c)
{
	char	**strs;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (0);
	i = 0;
	while (i <= count)
		strs[i++] = 0;
	return (strs);
}

static char	**freeturn(char	***data, char **ret)
{
	int	i;

	if (data && *data)
	{
		i = 0;
		while ((*data)[i])
		{
			free((*data)[i]);
			(*data)[i] = NULL;
			i++;
		}
		free(*data);
		*data = NULL;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		count;
	int		i;
	int		j;

	res = make_list(s, c);
	if (!res)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
			res[count] = ft_strndup(s + i, j);
		if (j > 0 && !res[count])
			return (freeturn(&res, 0));
		i += j;
		count++;
	}
	return (res);
}
