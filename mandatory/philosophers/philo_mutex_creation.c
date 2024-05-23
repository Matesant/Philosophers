/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:35:34 by matesant          #+#    #+#             */
/*   Updated: 2024/05/23 13:16:09 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_fork_mutex(void)
{
	int		id;
	t_mutex	*mutex;

	id = ft_get_rules()->numb_philo;
	mutex = ft_get_mutex();
	while (id >= 0)
	{
		if (pthread_mutex_init(&(mutex)->forks[id], NULL))
			return (1);
		id--;
	}
	if (pthread_mutex_init(&mutex->waiting_for_philo_take_fork, NULL))
		return (1);
	if (pthread_mutex_init(&mutex->write_rights, NULL))
		return (1);
	if (pthread_mutex_init(&mutex->meals_verification, NULL))
		return (1);
	if (pthread_mutex_init(&mutex->philo_dead_verification, NULL))
		return (1);
	return (0);
}
