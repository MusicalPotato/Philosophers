/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:12:53 by gorban            #+#    #+#             */
/*   Updated: 2023/08/29 16:43:01 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsadd_back(char ***strs, char *new, int size)
{
	int		i;
	char	**newstrs;

	if (!new)
		return (0);
	newstrs = malloc(sizeof(char *) * (size + 1));
	if (!newstrs)
		return (0);
	i = 0;
	while (i < size)
	{
		newstrs[i] = (*strs)[i];
		i++;
	}
	newstrs[i] = new;
	if (*strs)
		free(*strs);
	*strs = newstrs;
	return (1);
}
