/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:13:16 by gorban            #+#    #+#             */
/*   Updated: 2019/11/10 15:45:37 by gorban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	complet_line(char **line, char remains[BUFFER_SIZE + 1])
{
	int	a;
	int	b_size;

	b_size = 0;
	while (remains[b_size] && remains[b_size] != '\n')
		b_size++;
	if (remains[b_size] == '\n')
		b_size++;
	if (!b_size)
		return (1);
	*line = ft_memcat(*line, remains, ft_strlen(*line), b_size);
	if (!*line)
		return (0);
	a = 0;
	while (remains[b_size + a])
	{
		remains[a] = remains[b_size + a];
		a++;
	}
	while (remains[a])
		remains[a++] = '\0';
	return (1);
}

int	has_nl(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			r;
	static char	remains[OPEN_MAX + 1][BUFFER_SIZE + 1];

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (!has_nl(remains[fd]))
	{
		if (!(complet_line(&line, remains[fd])))
			return (NULL);
		r = read(fd, remains[fd], BUFFER_SIZE);
		if (r < 0)
		{
			free(line);
			return (NULL);
		}
		else if (r == 0)
			return (line);
		remains[fd][r] = '\0';
	}
	if (!(complet_line(&line, remains[fd])))
		return (NULL);
	return (line);
}
