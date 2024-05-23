/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:25:13 by matesant          #+#    #+#             */
/*   Updated: 2024/05/23 19:24:43 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_how_many_finished(void)
{
	int					how_many_philos_finished;
	int					id;
	t_philo				*philo;
	t_dining_etiquette	*rules;

	how_many_philos_finished = 0;
	id = 0;
	rules = ft_get_rules();
	while (id <= rules->numb_philo)
	{
		philo = &rules->philosophers[id];
		pthread_mutex_lock(&ft_get_mutex()->meals_verification);
		if (philo->eating_sessions >= rules->number_times_philo_must_eat)
			how_many_philos_finished++;
		pthread_mutex_unlock(&ft_get_mutex()->meals_verification);
		id++;
	}
	return (how_many_philos_finished);
}

t_bool	ft_there_is_a_corpse_on_table(t_philo *philo)
{
	if (ft_is_dead(philo))
	{
		ft_print_actions(philo, RED"😭 died"RESET);
		pthread_mutex_lock(&ft_get_mutex()->philo_dead_verification);
		ft_get_rules()->corpse = 1;
		pthread_mutex_unlock(&ft_get_mutex()->philo_dead_verification);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_completed_caloric_intake(t_dining_etiquette *rules)
{
	int	id;

	id = 0;
	if (rules->number_times_philo_must_eat == -1)
		return (FALSE);
	if (ft_how_many_finished() == rules->numb_philo)
	{
		pthread_mutex_lock(&ft_get_mutex()->meals_verification);
		rules->philos_finished_eating++;
		pthread_mutex_unlock(&ft_get_mutex()->meals_verification);
		return (TRUE);
	}
	return (FALSE);
}
