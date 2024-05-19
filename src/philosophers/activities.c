/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:34:54 by matesant          #+#    #+#             */
/*   Updated: 2024/05/19 16:55:36 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_get_forks(t_philo *philo);
void	ft_return_forks(t_philo *philo);

void	ft_print_actions(t_philo *philo, char *action);

void	ft_eat_meal(t_philo *philo)
{
	ft_get_forks(philo);
	ft_print_actions(philo, "is eating");
	usleep(ft_get_rules()->time_to_eat * 1000);
	philo->last_meal = ft_clock();
	philo->eating_sessions++;
	ft_return_forks(philo);
	ft_print_actions(philo, "is sleeping");
	usleep(ft_get_rules()->time_to_sleep * 1000);
	ft_print_actions(philo, "is thinking");
}

void	ft_print_actions(t_philo *philo, char *action)
{
	pthread_mutex_lock(&ft_get_rules()->write_rights);
	printf("%lld %d %s\n", ft_get_ms(), philo->id, action);
	pthread_mutex_unlock(&ft_get_rules()->write_rights);
}

void	ft_get_forks(t_philo *philo)
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

void	ft_return_forks(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = ft_get_rules()->forks;
	pthread_mutex_unlock(&forks[philo->left_fork]);
	pthread_mutex_unlock(&forks[philo->right_fork]);
}
