/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:00:40 by matesant          #+#    #+#             */
/*   Updated: 2024/05/20 23:55:24 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_exit(void);

void	*ft_philosophers_arrive_for_dinner(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(15000);
	while (1)
	{
		pthread_mutex_lock(&ft_get_rules()->write_rights);
		if (ft_get_rules()->corpse)
		{
			pthread_mutex_unlock(&ft_get_rules()->write_rights);
			ft_exit();
			return (NULL);
		}
		pthread_mutex_unlock(&ft_get_rules()->write_rights);
		if (ft_eat_meal(philo))
			break ;
		ft_print_actions(philo, "is sleeping");
		ft_activity_time(ft_get_rules()->time_to_sleep);
		ft_print_actions(philo, "is thinking");
	}
	ft_exit();
	return (NULL);
}

int	ft_philosophers_sit_down(t_dining_etiquette **rules)
{
	int	id;

	id = 0;
	(*rules)->program_start_time = ft_clock();
	while (id < (*rules)->numb_philo)
	{
		if (pthread_create(&(*rules)->philosophers[id].philo_action, NULL,
				ft_philosophers_arrive_for_dinner,
				(void *)&(*rules)->philosophers[id]))
			return (1);
		pthread_mutex_lock(&(*rules)->write_rights);
		(*rules)->philosophers[id].last_meal = ft_get_ms();
		pthread_mutex_unlock(&(*rules)->write_rights);
		id++;
	}
	ft_historian();
	return (0);
}

void	ft_exit(void)
{
	t_dining_etiquette	*rules;
	int					id;

	rules = ft_get_rules();
	id = 0;
	while (id < rules->numb_philo)
	{
		pthread_join(rules->philosophers[id].philo_action, NULL);
		id++;
	}
	id = 0;
	while (id < rules->numb_philo)
	{
		pthread_mutex_destroy(&rules->forks[id]);
		id++;
	}
	pthread_mutex_destroy(&rules->waiting_for_philo_take_fork);
	pthread_mutex_destroy(&rules->write_rights);
	pthread_mutex_unlock(&rules->write_rights);
}
