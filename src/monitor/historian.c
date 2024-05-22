/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:03:18 by matesant          #+#    #+#             */
/*   Updated: 2024/05/22 13:27:39 by matesant         ###   ########.fr       */
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
		while ((philo_id < ft_get_rules()->numb_philo))
		{
			if (ft_is_dead(&rules->philosophers[philo_id]))
			{
				ft_print_actions(&rules->philosophers[philo_id], "died");
				pthread_mutex_lock(&ft_get_mutex()->philo_dead_verification);
				rules->corpse = 1;
				pthread_mutex_unlock(&ft_get_mutex()->philo_dead_verification);
				return ;
			}
			philo_id++;
		}
	}
}
