/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:16:04 by matesant          #+#    #+#             */
/*   Updated: 2024/05/28 18:32:48 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void		ft_get_forks(t_philo *philo);
void		ft_return_forks(void);
static void	ft_update_last_meal_time(t_philo *philo);

void	ft_eat(t_philo *philo)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	ft_get_forks(philo);
	ft_print_actions(philo, "is eating");
	if (ft_activity_time(rules->time_to_eat, philo))
	{
		printf("%lld philo %d died\n", ft_get_ms(), philo->id);
		exit(1);
	}
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
