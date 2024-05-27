/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:16:51 by matesant          #+#    #+#             */
/*   Updated: 2024/05/23 13:17:26 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_exit(void)
{
	t_dining_etiquette	*rules;
	t_mutex				*mutex;
	int					id;

	rules = ft_get_rules();
	mutex = ft_get_mutex();
	id = 0;
	while (id < rules->numb_philo)
	{
		pthread_join(rules->philosophers[id].philo_action, NULL);
		id++;
	}
	id = 0;
	while (id < rules->numb_philo)
	{
		pthread_mutex_destroy(&mutex->forks[id]);
		id++;
	}
	pthread_mutex_destroy(&mutex->waiting_for_philo_take_fork);
	pthread_mutex_destroy(&mutex->write_rights);
	pthread_mutex_destroy(&mutex->meals_verification);
	pthread_mutex_destroy(&mutex->philo_dead_verification);
}
