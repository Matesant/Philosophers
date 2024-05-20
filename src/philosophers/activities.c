/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:34:54 by matesant          #+#    #+#             */
/*   Updated: 2024/05/19 21:03:50 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_get_forks(t_philo *philo);
static void	ft_return_forks(t_philo *philo);
static void	ft_update_last_meal_time(t_philo *philo);

void	ft_eat_meal(t_philo *philo)
{
	ft_get_forks(philo);
	ft_print_actions(philo, "is eating");
	ft_activity_time(ft_get_rules()->time_to_eat);
	ft_update_last_meal_time(philo);
	ft_return_forks(philo);
}

static void	ft_get_forks(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = ft_get_rules()->forks;
	pthread_mutex_lock(&ft_get_rules()->waiting_for_philo_take_fork);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&forks[philo->right_fork]);
		ft_print_actions(philo, "has taken a fork");
		pthread_mutex_lock(&forks[philo->left_fork]);
		ft_print_actions(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&forks[philo->left_fork]);
		ft_print_actions(philo, "has taken a fork");
		pthread_mutex_lock(&forks[philo->right_fork]);
		ft_print_actions(philo, "has taken a fork");
	}
	pthread_mutex_unlock(&ft_get_rules()->waiting_for_philo_take_fork);
}

static void	ft_return_forks(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = ft_get_rules()->forks;
	pthread_mutex_unlock(&forks[philo->left_fork]);
	pthread_mutex_unlock(&forks[philo->right_fork]);
}

static void	ft_update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&ft_get_rules()->write_rights);
	philo->last_meal = ft_get_ms();
	pthread_mutex_unlock(&ft_get_rules()->write_rights);
	philo->eating_sessions++;
}
