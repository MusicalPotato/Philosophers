/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grorban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:52:21 by grorban           #+#    #+#             */
/*   Updated: 2023/12/19 15:52:21 by grorban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/libft.h"
# include "philo_struct.h"
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>

int		setup_prog(int argc, char **argv, t_data *data);

time_t	ft_get_time(void);
void	ft_sleep(time_t u_time, t_philo *philo);

#endif
