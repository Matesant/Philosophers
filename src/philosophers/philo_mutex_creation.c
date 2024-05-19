/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:35:34 by matesant          #+#    #+#             */
/*   Updated: 2024/05/19 11:54:38 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_set_philosophers_rules(t_dining_etiquette **rules)
{
	int	id;

	id = (*rules)->numb_philo;
	while (id >= 0)
	{
		(*rules)->philosophers[id].left_fork = id;
		(*rules)->philosophers[id].id = id + 1;
		(*rules)->philosophers[id].right_fork = (id + 1) % (*rules)->numb_philo;
		id--;
	}
}

void	ft_init_fork_mutex(void)
{
	int					id;
	t_dining_etiquette	*rules;

	id = ft_get_rules()->numb_philo - 1;
	rules = ft_get_rules();
	while (id >= 0)
	{
		pthread_mutex_init(&(rules)->forks[id], NULL);
		id--;
	}
}
