/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:34:54 by matesant          #+#    #+#             */
/*   Updated: 2024/05/17 23:56:20 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat_meal(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = ft_get_rules()->forks;
	pthread_mutex_lock(&forks[philo->left_fork]);
	pthread_mutex_lock(&forks[philo->right_fork]);
	usleep(ft_get_rules()->time_to_eat * 100);
	printf("Philosopher %d is eating\n", philo->id);
	pthread_mutex_unlock(&forks[philo->left_fork]);
	pthread_mutex_unlock(&forks[philo->right_fork]);
	printf("Philosopher %d is sleeping\n", philo->id);
}
