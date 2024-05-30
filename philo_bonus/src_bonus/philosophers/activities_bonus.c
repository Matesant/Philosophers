/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:16:04 by matesant          #+#    #+#             */
/*   Updated: 2024/05/30 00:31:15 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void		ft_get_forks(t_philo *philo);
void		ft_return_forks(void);
static void	ft_update_last_meal_time(t_philo *philo);

void	ft_eat(t_philo *philo)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	ft_get_forks(philo);
	ft_print_actions(philo, "is eating");
	ft_activity_time(rules->time_to_eat, philo);
	ft_update_last_meal_time(philo);
	ft_return_forks();
}

void	ft_get_forks(t_philo *philo)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	sem_wait(rules->forks);
	sem_wait(rules->forks);
	ft_print_actions(philo, "has taken a fork");
	ft_print_actions(philo, "has taken a fork");
}

void	ft_return_forks(void)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	sem_post(rules->forks);
	sem_post(rules->forks);
}

static void	ft_update_last_meal_time(t_philo *philo)
{
	philo->last_meal = ft_get_ms();
	philo->eating_sessions++;
}

void	ft_sleep(t_philo *philo)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	if (ft_activity_time(rules->time_to_sleep, philo))
	{
		ft_print_actions(philo, "is sleeping");
		exit(EXIT_FAILURE);
	}
}
