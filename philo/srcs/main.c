/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:45:59 by grorban           #+#    #+#             */
/*   Updated: 2023/12/19 15:46:00 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->printing);
	if (!*(philo->end))
		printf("\033[96m%ld\033[95m %d\033[0m %s\n", ft_get_time() - philo->start, philo->sit, action);
	pthread_mutex_unlock(philo->printing);
}

void	go_spaghettito(t_philo *philo)
{
	printf("\033[96m%ld\033[95m %d \033[0mis waiting for left fork = %p\n", ft_get_time() - philo->start, philo->sit, philo->forks[0]);
	pthread_mutex_lock(philo->forks[0]);
	printf("\033[96m%ld\033[95m %d \033[0mhas taken left fork = %p\n", ft_get_time() - philo->start, philo->sit, philo->forks[0]);
	print_action(philo, "\033[90mhas taken a fork\033[0m");
	printf("\033[96m%ld\033[95m %d \033[0mis waiting for right fork = %p\n", ft_get_time() - philo->start, philo->sit, philo->forks[1]);
	pthread_mutex_lock(philo->forks[1]);
	printf("\033[96m%ld\033[95m %d \033[0mhas taken right fork = %p\n", ft_get_time() - philo->start, philo->sit, philo->forks[1]);
	print_action(philo, "\033[90mhas taken a fork\033[0m");
	pthread_mutex_lock(philo->eating);
	printf("\033[96m%ld\033[95m %d \033[0mstart eating\n", ft_get_time() - philo->start, philo->sit);
	philo->is_eating = 1;
	philo->last_eat = ft_get_time();
	print_action(philo, "\033[92mis eating\033[0m");
	pthread_mutex_unlock(philo->eating);
	ft_sleep(philo->time_to_eat, philo);
	pthread_mutex_lock(philo->eating);
	if (philo->must_eat > 0)
		philo->must_eat--;
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->eating);
	printf("\033[96m%ld\033[95m %d \033[0mend eating\n", ft_get_time() - philo->start, philo->sit);
	pthread_mutex_unlock(philo->forks[1]);
	printf("\033[96m%ld\033[95m %d \033[0mhas drop right fork = %p\n", ft_get_time() - philo->start, philo->sit, philo->forks[1]);
	pthread_mutex_unlock(philo->forks[0]);
	printf("\033[96m%ld\033[95m %d \033[0mhas drop left fork = %p\n", ft_get_time() - philo->start, philo->sit, philo->forks[0]);
}

void	*go_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (!(philo->sit % 2))
		ft_sleep(philo->time_to_eat / 2, philo);
	printf("\033[96m%ld\033[95m %d \033[0mstart his routine\n", ft_get_time() - philo->start, philo->sit);
	pthread_mutex_lock(philo->printing);
	while (!(*philo->end))
	{
		pthread_mutex_unlock(philo->printing);
		go_spaghettito(philo);
		print_action(philo, "\033[94mis sleeping\033[0m");
		ft_sleep(philo->time_to_sleep, philo);
		print_action(philo, "\033[93mis thinking\033[0m");
		pthread_mutex_lock(philo->printing);
	}
	pthread_mutex_unlock(philo->printing);
	printf("\033[96m%ld\033[95m %d \033[0mend routine\n", ft_get_time() - philo->start, philo->sit);
	return (NULL);
}

void	*watch_it(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	data = (t_data *)arg;
	while (!data->end)
	{
		philo = data->philo;
		data->finish_eat = 0;
		i = 0;
		while (!data->end && i < data->n_philo)
		{
			pthread_mutex_lock(philo->eating);
			if (!philo->is_eating)
			{
				if (ft_get_time() - philo->last_eat > philo->time_to_die)
				{
					pthread_mutex_lock(philo->printing);
					data->end = 1;
					printf("\033[96m%ld\033[95m %d \033[91mdied\033[0m\n", ft_get_time() - philo->start, philo->sit);
					pthread_mutex_unlock(philo->printing);
				}
			}
			if (philo->must_eat == 0)
				data->finish_eat++;
			pthread_mutex_unlock(philo->eating);
			philo++;
			i++;
		}
		if (data->finish_eat == data->n_philo)
		{
			pthread_mutex_lock(data->dying);
			data->end = 1;
			pthread_mutex_unlock(data->dying);
		}
		//usleep(1000);
	}
	printf("end watching\n");
	return (NULL);
}

int	create_live(t_data *data)
{
	int		i;
	int		error;
	time_t	start;

	i = 0;
	start = ft_get_time();
	while (i < data->n_philo)
	{
		data->philo[i].start = start;
		data->philo[i].last_eat = start;
		error = pthread_create(&(data->philo[i].id_routine), NULL, &go_routine, (void *)(data->philo + i));
		if (error != 0)
			return (0);
		i++;
	}
	error = pthread_create(&(data->philo[i].id_watch), NULL, &watch_it, (void *)(data));
	if (error != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (!setup_prog(argc, argv, &data))
		return (0);
	create_live(&data);
	i = 0;
	while (i < data.n_philo)
	{
		pthread_join(data.philo[i].id_routine, NULL);
		pthread_join(data.philo[i].id_watch, NULL);
		i++;
	}
	return (0);
}
