/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:30:22 by grorban           #+#    #+#             */
/*   Updated: 2023/04/04 13:30:23 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	nbr;
	int		signe;

	nbr = 0;
	signe = 1;
	if (!str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		signe *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		if (nbr < 0)
			return ((signe + 1) / -2);
		str++;
	}
	return ((int)nbr * signe);
}
