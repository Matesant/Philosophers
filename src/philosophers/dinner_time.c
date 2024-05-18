/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:00:40 by matesant          #+#    #+#             */
/*   Updated: 2024/05/17 23:21:20 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_philosophers_arrive_for_dinner(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (1)
	{
		ft_eat_meal(philo);
	}
	return (NULL);
}

void	ft_philosophers_sit_down(t_dining_etiquette **rules)
{
	int	id;

	id = 0;
	while (id < (*rules)->numb_philo)
	{
		pthread_create(&(*rules)->philosophers[id].philo_action, NULL,
			ft_philosophers_arrive_for_dinner,
			(void *)&(*rules)->philosophers[id]);
		id++;
	}
	while (id)
	{
		pthread_join((*rules)->philosophers[id].philo_action, NULL);
		id--;
	}
}
