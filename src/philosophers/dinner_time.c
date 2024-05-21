/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:00:40 by matesant          #+#    #+#             */
/*   Updated: 2024/05/21 17:22:05 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_wait_for_threads_finish(void);
t_bool	ft_dead_or_alive(void);

void	ft_exit(void);

void	*ft_philosophers_arrive_for_dinner(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(10000);
	while (ft_dead_or_alive())
	{
		ft_eat_meal(philo);
		ft_print_actions(philo, "is sleeping");
		ft_activity_time(ft_get_rules()->time_to_sleep);
		ft_print_actions(philo, "is thinking");
		ft_activity_time(1);
	}
	ft_exit();
	return (NULL);
}

int	ft_philosophers_sit_down(t_dining_etiquette **rules)
{
	int	id;

	id = 0;
	(*rules)->program_start_time = ft_return_time_of_day();
	while (id < (*rules)->numb_philo)
	{
		pthread_mutex_lock(&(*rules)->write_rights);
		if (pthread_create(&(*rules)->philosophers[id].philo_action, NULL,
				ft_philosophers_arrive_for_dinner,
				(void *)&(*rules)->philosophers[id]))
			return (1);
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
	ft_wait_for_threads_finish();
	while (id < rules->numb_philo)
	{
		pthread_mutex_destroy(&rules->forks[id]);
		id++;
	}
	pthread_mutex_destroy(&rules->waiting_for_philo_take_fork);
	pthread_mutex_destroy(&rules->write_rights);
}

void	ft_wait_for_threads_finish(void)
{
	t_dining_etiquette	*rules;
	pthread_mutex_t		philo;

	rules = ft_get_rules();
	pthread_mutex_init(&philo, NULL);
	pthread_mutex_lock(&rules->write_rights);
	rules->philos_finished++;
	pthread_mutex_unlock(&rules->write_rights);
	while (1)
	{
		if (rules->philos_finished == rules->numb_philo)
			break ;
	}
}

t_bool	ft_dead_or_alive(void)
{
	t_dining_etiquette *rules;

	rules = ft_get_rules();
	pthread_mutex_lock(&rules->write_rights);
	if (!rules->corpse)
	{
		pthread_mutex_unlock(&rules->write_rights);
		return (TRUE);
	}
	pthread_mutex_unlock(&rules->write_rights);
	return (FALSE);
}