/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_verification.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:15:56 by matesant          #+#    #+#             */
/*   Updated: 2024/05/22 18:16:15 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_dead_or_alive(void)
{
	t_dining_etiquette	*rules;
	t_mutex				*mutex;

	rules = ft_get_rules();
	mutex = ft_get_mutex();
	pthread_mutex_lock(&mutex->philo_dead_verification);
	if (rules->corpse)
	{
		pthread_mutex_unlock(&mutex->philo_dead_verification);
		return (TRUE);
	}
	pthread_mutex_unlock(&mutex->philo_dead_verification);
	return (FALSE);
}

t_bool	ft_all_eaten(void)
{
	t_dining_etiquette	*rules;
	t_mutex				*mutex;

	rules = ft_get_rules();
	mutex = ft_get_mutex();
	pthread_mutex_lock(&mutex->meals_verification);
	if (rules->philos_finished_eating)
	{
		pthread_mutex_unlock(&mutex->meals_verification);
		return (TRUE);
	}
	pthread_mutex_unlock(&mutex->meals_verification);
	return (FALSE);
}
