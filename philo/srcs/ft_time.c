/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:39:23 by grorban           #+#    #+#             */
/*   Updated: 2024/01/24 15:39:23 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

time_t	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	ft_sleep(time_t u_time, t_philo *philo)
{
	time_t	start;

	start = ft_get_time();
	pthread_mutex_lock(philo->dying);
	while (ft_get_time() - start < u_time && !*(philo->end))
	{
		pthread_mutex_unlock(philo->dying);
		usleep(200);
		pthread_mutex_lock(philo->dying);
	}
	pthread_mutex_unlock(philo->dying);
}
