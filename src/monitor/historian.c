/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:03:18 by matesant          #+#    #+#             */
/*   Updated: 2024/05/19 22:38:41 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_historian(void)
{
	int					philo_id;
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	philo_id = 0;
	while ((philo_id < ft_get_rules()->numb_philo - 1) && !rules->corpse)
	{
		pthread_mutex_lock(&rules->write_rights);
		if (ft_get_ms()
			- rules->philosophers[philo_id].last_meal > rules->time_to_die)
		{
			printf("%lld %d died\n", ft_get_ms(),
				rules->philosophers[philo_id].id);
			rules->corpse = 1;
			break ;
		}
		pthread_mutex_unlock(&rules->write_rights);
		usleep(100);
		philo_id++;
	}
}
