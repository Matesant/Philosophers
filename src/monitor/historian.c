/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:03:18 by matesant          #+#    #+#             */
/*   Updated: 2024/05/22 15:49:00 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_bool	ft_there_is_a_corpse_on_table(t_philo *philo);
t_bool	ft_completed_caloric_intake(t_dining_etiquette *rules);

void	ft_historian(void)
{
	int					philo_id;
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	while (1)
	{
		philo_id = 0;
		while ((philo_id < ft_get_rules()->numb_philo))
		{
			if (ft_there_is_a_corpse_on_table(&rules->philosophers[philo_id]))
				return ;
			if ((ft_completed_caloric_intake(rules)))
				return ;
			philo_id++;
		}
	}
}

t_bool	ft_there_is_a_corpse_on_table(t_philo *philo)
{
	if (ft_is_dead(philo))
	{
		ft_print_actions(philo, "died");
		pthread_mutex_lock(&ft_get_mutex()->philo_dead_verification);
		ft_get_rules()->corpse = 1;
		pthread_mutex_unlock(&ft_get_mutex()->philo_dead_verification);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_completed_caloric_intake(t_dining_etiquette *rules)
{
	int		id;

	id = 0;
	if (rules->number_times_philo_must_eat == -1)
		return (FALSE);
	if (ft_how_many_finished() == rules->number_times_philo_must_eat)
	{
		pthread_mutex_lock(&ft_get_mutex()->meals_verification);
		rules->philos_finished_eating++;
		pthread_mutex_unlock(&ft_get_mutex()->meals_verification);
		return (TRUE);
	}
	return (FALSE);
}
