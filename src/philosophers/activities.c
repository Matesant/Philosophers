/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:34:54 by matesant          #+#    #+#             */
/*   Updated: 2024/05/18 01:52:11 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat_meal(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = ft_get_rules()->forks;
	pthread_mutex_lock(&forks[philo->left_fork]);
	pthread_mutex_lock(&forks[philo->right_fork]);
	gettimeofday(&philo->last_meal, NULL);
	printf("%ld %d is eating\n", philo->last_meal.tv_usec, philo->id);
	philo->eating_sessions++;
	usleep(ft_get_rules()->time_to_eat);
	pthread_mutex_unlock(&forks[philo->left_fork]);
	pthread_mutex_unlock(&forks[philo->right_fork]);
	printf("%ld %d is sleeping\n", philo->last_meal.tv_usec, philo->id);
	usleep(ft_get_rules()->time_to_sleep);
	printf("Philosopher %d is thinking\n", philo->id);
}
