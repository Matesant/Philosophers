/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:00:40 by matesant          #+#    #+#             */
/*   Updated: 2024/05/20 00:52:58 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_philosophers_arrive_for_dinner(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(15000);
	while (!ft_get_rules()->corpse)
	{
		if (ft_eat_meal(philo))
			return (NULL);
		ft_print_actions(philo, "is sleeping");
		ft_activity_time(ft_get_rules()->time_to_sleep);
		ft_print_actions(philo, "is thinking");
	}
	return (NULL);
}

int	ft_philosophers_sit_down(t_dining_etiquette **rules)
{
	int			id;

	id = 0;
	(*rules)->program_start_time = ft_clock();
	while (id < (*rules)->numb_philo)
	{
		if (pthread_create(&(*rules)->philosophers[id].philo_action, NULL,
				ft_philosophers_arrive_for_dinner,
				(void *)&(*rules)->philosophers[id]))
			return (1);
		(*rules)->philosophers[id].last_meal = ft_get_ms();
		id++;
	}
	ft_historian();
	while (id >= 0)
	{
		pthread_join((*rules)->philosophers[id].philo_action, NULL);
		id--;
	}
	return (0);
}
