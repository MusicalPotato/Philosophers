/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:54:59 by grorban           #+#    #+#             */
/*   Updated: 2023/04/04 15:55:00 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*tab;
	int		size;
	long	nb;

	nb = n;
	size = ft_intlen(nb);
	tab = malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (0);
	if (nb < 0)
	{
		tab[0] = '-';
		nb = nb * -1;
	}
	tab[size--] = '\0';
	while (nb > 9)
	{
		tab[size--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	tab[size] = nb + '0';
	return (tab);
}
