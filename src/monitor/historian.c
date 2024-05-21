/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:03:18 by matesant          #+#    #+#             */
/*   Updated: 2024/05/20 21:35:15 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_historian(void)
{
	int					philo_id;
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	while (1)
	{
		philo_id = 0;
		while ((philo_id < ft_get_rules()->numb_philo) && !rules->philo_dead)
		{
			pthread_mutex_lock(&rules->waiting_for_philo_take_fork);
			if (ft_get_ms()
				- rules->philosophers[philo_id].last_meal > rules->time_to_die)
			{
				pthread_mutex_lock(&rules->write_rights);
				printf("%lld %d died\n", ft_get_ms(),
					rules->philosophers[philo_id].id);
				rules->corpse = 1;
				rules->philo_dead = 1;
				pthread_mutex_unlock(&rules->write_rights);
				return ;
			}
			pthread_mutex_unlock(&rules->waiting_for_philo_take_fork);
			philo_id++;
		}
	}
}
