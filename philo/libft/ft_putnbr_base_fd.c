/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:06:29 by grorban           #+#    #+#             */
/*   Updated: 2023/04/14 11:06:29 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_checkbase(char *base)
{
	size_t	base_size;
	size_t	i;

	base_size = 0;
	if (base)
	{
		while (base[base_size])
		{
			if (base[base_size] == '+' || base[base_size] == '-')
				return (0);
			i = base_size + 1;
			while (base[i])
			{
				if (base[i] == base[base_size])
					return (0);
				i++;
			}
			base_size++;
		}
	}
	return (base_size);
}

static int	ft_write_nbr_base(unsigned long n, char *base, size_t bsize, int fd)
{
	int	size;

	size = 0;
	if (n > bsize - 1)
		size += ft_write_nbr_base(n / bsize, base, bsize, fd);
	size += write(fd, &base[n % bsize], 1);
	return (size);
}

int	ft_putnbr_base_fd(unsigned int n, char *base, int fd)
{
	size_t	bsize;

	bsize = ft_checkbase(base);
	if (bsize > 1)
		return (ft_write_nbr_base(n, base, bsize, fd));
	return (0);
}
