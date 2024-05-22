/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:00:40 by matesant          #+#    #+#             */
/*   Updated: 2024/05/22 18:17:01 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_philosophers_sit_down(t_dining_etiquette **rules)
{
	int	id;

	id = 0;
	(*rules)->program_start_time = ft_return_time_of_day();
	while (id < (*rules)->numb_philo)
	{
		if ((*rules)->numb_philo == 1)
		{
			if (pthread_create(&(*rules)->philosophers[id].philo_action, NULL,
					ft_alone_in_the_dark, (void *)&(*rules)->philosophers[id]))
				return (1);
		}
		else if (pthread_create(&(*rules)->philosophers[id].philo_action, NULL,
				ft_philosophers_arrive_for_dinner,
				(void *)&(*rules)->philosophers[id]))
			return (1);
		pthread_mutex_lock(&ft_get_mutex()->meals_verification);
		(*rules)->philosophers[id].last_meal = ft_get_ms();
		pthread_mutex_unlock(&ft_get_mutex()->meals_verification);
		id++;
	}
	ft_historian();
	return (0);
}

