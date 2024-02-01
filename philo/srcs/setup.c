/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:08:14 by grorban           #+#    #+#             */
/*   Updated: 2024/01/24 15:08:15 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_arg_validity(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(" : numeric argmuments required\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_data(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!check_arg_validity(argv[i]))
			return (0);
		i++;
	}
	data->end = 0;
	data->finish_eat = 0;
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat = -1;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	return (1);
}

t_philo	*setup_philo(t_data *data)
{
	t_philo	*philosophers;
	int		i;

	philosophers = malloc(sizeof(t_philo) * data->n_philo);
	if (!philosophers)
		return (NULL);
	i = 0;
	while (i < data->n_philo)
	{
		philosophers[i].sit = i + 1;
		philosophers[i].end = &(data->end);
		philosophers[i].finish_eat = &(data->finish_eat);
		philosophers[i].is_eating = 0;
		philosophers[i].must_eat = data->must_eat;
		philosophers[i].time_to_eat = data->time_to_eat;
		philosophers[i].time_to_sleep = data->time_to_sleep;
		philosophers[i].time_to_die = data->time_to_die;
		i++;
	}
	return (philosophers);
}

pthread_mutex_t	*table_mutex(int n)
{
	pthread_mutex_t	*mutex_lst;
	int				i;

	mutex_lst = malloc(sizeof(pthread_mutex_t) * n);
	if (!mutex_lst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&(mutex_lst[i]), NULL) != 0)
		{ 
			ft_putstr_fd("\nmutex init has failed\n", 2); 
			return (NULL);
		}
		i++;
	}
	return (mutex_lst);
}

int	init_mutex(t_data *data, t_philo *philo)
{
	int	i;

	data->forks = table_mutex(data->n_philo);
	data->eating = table_mutex(data->n_philo);
	data->dying = malloc(sizeof(pthread_mutex_t));
	data->printing = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(data->printing, NULL) != 0)
	{ 
		ft_putstr_fd("\nmutex init has failed\n", 2); 
		return (0);
	}
	if (pthread_mutex_init(data->dying, NULL) != 0)
	{ 
		ft_putstr_fd("\nmutex init has failed\n", 2); 
		return (0);
	}
	i = 0;
	while (i < data->n_philo)
	{
		printf("setup philo %d/%d\n", philo[i].sit, data->n_philo);
		philo[i].forks[0] = data->forks + i;
		printf("left fork = %p\n", philo[i].forks[0]);
		philo[i].forks[1] = data->forks + (i + 1) % data->n_philo;
		printf("right fork = %p\n", philo[i].forks[1]);
		philo[i].eating = data->eating + i;
		printf("eating mutex = %p\n", philo[i].eating);
		philo[i].printing = data->printing;
		printf("printing mutex = %p\n", philo[i].printing);
		philo[i].dying = data->dying;
		printf("dying mutex = %p\n", philo[i].dying);
		i++;
	}
	return (1);
}

int	setup_prog(int argc, char **argv, t_data *data)
{
	t_philo	*philosophers;

	printf("setup_data\n");
	if (!get_data(argc, argv, data))
		return (0);
	printf("setup_philo\n");
	philosophers = setup_philo(data);
	if (!philosophers)
		return (0);
	data->philo = philosophers;
	printf("build_forks\n");
	if (!init_mutex(data, philosophers))
		return (0);
	
	return (1);
}
