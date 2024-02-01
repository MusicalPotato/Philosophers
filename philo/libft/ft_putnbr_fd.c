/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:17:36 by grorban           #+#    #+#             */
/*   Updated: 2023/04/04 16:17:36 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long n, int fd)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size += ft_putchar_fd('-', fd);
	}
	if (n > 9)
		size += ft_putnbr_fd(n / 10, fd);
	size += ft_putchar_fd(n % 10 + '0', fd);
	return (size);
}
