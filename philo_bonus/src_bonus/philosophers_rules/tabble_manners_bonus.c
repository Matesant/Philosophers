/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabble_manners_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:02:46 by matesant          #+#    #+#             */
/*   Updated: 2024/05/29 19:15:31 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_put_id(t_philo *philo, int id);

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

void	ft_init_philos(void)
{
	int					id;
	t_dining_etiquette	*rules;

	id = 0;
	rules = ft_get_rules();
	while (id < rules->numb_philo)
	{
		ft_put_id(&rules->philosophers[id], id);
		id++;
	}
}

void	ft_put_id(t_philo *philo, int id)
{
	philo->id = id + 1;
	philo->last_meal = 0;
	philo->eating_sessions = 0;
}
