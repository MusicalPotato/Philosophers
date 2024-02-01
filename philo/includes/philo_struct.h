/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:54:25 by grorban           #+#    #+#             */
/*   Updated: 2023/12/19 15:54:26 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philosopher
{
	pthread_t		id_routine;
	pthread_t		id_watch;
	int				sit;
	pthread_mutex_t	*forks[2];
	pthread_mutex_t	*printing;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*dying;
	int				*end;
	int				must_eat;
	int				is_eating;
	int				*finish_eat;
	time_t			start;
	time_t			last_eat;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
}				t_philo;

typedef struct	s_data
{
	int				n_philo;
	t_philo			*philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat;
	int				end;
	int				finish_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*printing;
	pthread_mutex_t	*dying;
}				t_data;

#endif
