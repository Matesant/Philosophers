/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:34:54 by matesant          #+#    #+#             */
/*   Updated: 2024/05/23 19:26:35 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_get_forks(t_philo *philo);
static void	ft_return_forks(t_philo *philo);
static void	ft_update_last_meal_time(t_philo *philo);

t_bool	ft_eat_meal(t_philo *philo)
{
	ft_get_forks(philo);
	ft_print_actions(philo, CYAN"😋 is eating"RESET);
	ft_activity_time(ft_get_rules()->time_to_eat);
	ft_update_last_meal_time(philo);
	ft_return_forks(philo);
	return (FALSE);
}

static void	ft_get_forks(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = ft_get_mutex()->forks;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&forks[philo->right_fork]);
		ft_print_actions(philo, YELLOW"🍽️  has taken a fork"RESET);
		pthread_mutex_lock(&forks[philo->left_fork]);
		ft_print_actions(philo, YELLOW"🍽️  has taken a fork"RESET);
	}
	else
	{
		pthread_mutex_lock(&forks[philo->left_fork]);
		ft_print_actions(philo, YELLOW"🍽️  has taken a fork"RESET);
		pthread_mutex_lock(&forks[philo->right_fork]);
		ft_print_actions(philo, YELLOW"🍽️  has taken a fork"RESET);
	}
}

static void	ft_return_forks(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = ft_get_mutex()->forks;
	pthread_mutex_unlock(&forks[philo->left_fork]);
	pthread_mutex_unlock(&forks[philo->right_fork]);
}

static void	ft_update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&ft_get_mutex()->meals_verification);
	philo->last_meal = ft_get_ms();
	philo->eating_sessions++;
	pthread_mutex_unlock(&ft_get_mutex()->meals_verification);
}
