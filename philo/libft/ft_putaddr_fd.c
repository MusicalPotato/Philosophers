/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:06:51 by grorban           #+#    #+#             */
/*   Updated: 2023/04/18 14:06:52 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddr_fd(void *addr, int fd)
{
	int		i;
	char	*hexa;
	char	bit;
	int		size;

	hexa = "0123456789abcdef";
	i = 16;
	size = 0;
	bit = '0';
	while (i > 0 && bit == '0')
		bit = hexa[(((unsigned long)addr) >> ((i--) * 4 - 4)) & 0xf];
	while (i >= 0)
	{
		size += write(fd, &bit, 1);
		bit = hexa[(((unsigned long)addr) >> ((i--) * 4 - 4)) & 0xf];
	}
	return (size);
}
