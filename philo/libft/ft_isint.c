/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:55:45 by grorban           #+#    #+#             */
/*   Updated: 2023/05/31 12:55:47 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *num)
{
	int		i;
	size_t	neg;
	char	*int_max;

	int_max = "2147483647";
	i = 0;
	neg = 0;
	if (!num)
		return (0);
	if (num[0] == '-')
	{
		int_max = "2147483648";
		neg = 1;
	}
	while (num[i + neg])
	{
		if (!ft_isdigit(num[i + neg]))
			return (0);
		if (num[i + neg] > int_max[i] && ft_strlen(num) - neg >= 10)
			return (0);
		i++;
	}
	if (i == 0 || i > 10)
		return (0);
	return (1);
}
