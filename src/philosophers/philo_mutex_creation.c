/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:35:34 by matesant          #+#    #+#             */
/*   Updated: 2024/05/20 23:50:36 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_init_fork_mutex(void)
{
	int					id;
	t_dining_etiquette	*rules;

	id = ft_get_rules()->numb_philo;
	rules = ft_get_rules();
	while (id >= 0)
	{
		if (pthread_mutex_init(&(rules)->forks[id], NULL))
			return (1);
		id--;
	}
	if (pthread_mutex_init(&rules->waiting_for_philo_take_fork, NULL))
		return (1);
	if (pthread_mutex_init(&rules->write_rights, NULL))
		return (1);
	return (0);
}
