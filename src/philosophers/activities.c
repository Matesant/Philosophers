/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:34:54 by matesant          #+#    #+#             */
/*   Updated: 2024/05/19 12:52:52 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_get_ms(void);

void	ft_eat_meal(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = ft_get_rules()->forks;
	pthread_mutex_lock(&ft_get_rules()->waiting_for_philo_take_fork);
	pthread_mutex_lock(&forks[philo->right_fork]);
	printf("%lld %d has taken a fork\n", ft_get_ms(), philo->id);
	pthread_mutex_lock(&forks[philo->left_fork]);
	printf("%lld %d has taken a fork\n", ft_get_ms(), philo->id);
	pthread_mutex_unlock(&ft_get_rules()->waiting_for_philo_take_fork);
	philo->last_meal = ft_update_timestamp();
	printf("%lld %d is eating\n", ft_get_ms(), philo->id);
	usleep(ft_get_rules()->time_to_eat * 1000);
	philo->eating_sessions++;
	pthread_mutex_unlock(&forks[philo->right_fork]);
	pthread_mutex_unlock(&forks[philo->left_fork]);
	printf("%lld %d is sleeping\n", ft_get_ms(), philo->id);
	usleep(ft_get_rules()->time_to_sleep * 1000);
	printf("%lld %d is thinking\n", ft_get_ms(), philo->id);
}

long long	ft_update_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_get_ms(void)
{
	return (ft_update_timestamp() - ft_get_rules()->program_start_time);
}
