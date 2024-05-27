/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabble_manners.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:02:46 by matesant          #+#    #+#             */
/*   Updated: 2024/05/20 23:50:59 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_set_tabble_manners(t_dining_etiquette **tabble_manners, char **argv)
{
	(*tabble_manners)->numb_philo = ft_atol(argv[1]);
	(*tabble_manners)->time_to_die = ft_atol(argv[2]);
	(*tabble_manners)->time_to_eat = ft_atol(argv[3]);
	(*tabble_manners)->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		(*tabble_manners)->number_times_philo_must_eat = ft_atol(argv[5]);
	else
		(*tabble_manners)->number_times_philo_must_eat = -1;
}

void	ft_set_philosophers_rules(t_dining_etiquette **rules)
{
	int	id;

	id = (*rules)->numb_philo - 1;
	while (id >= 0)
	{
		(*rules)->philosophers[id].left_fork = id;
		(*rules)->philosophers[id].id = id + 1;
		(*rules)->philosophers[id].right_fork = (id + 1) % (*rules)->numb_philo;
		id--;
	}
}
