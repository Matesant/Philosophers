/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_measure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:49:05 by matesant          #+#    #+#             */
/*   Updated: 2024/05/22 13:17:38 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_return_time_of_day(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_get_ms(void)
{
	return (ft_return_time_of_day() - ft_get_rules()->program_start_time);
}

void	ft_activity_time(long long time)
{
	if (!ft_dead_or_alive())
		usleep(time * 1000);
}

t_bool	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&ft_get_mutex()->meals_verification);
	if (ft_get_ms() - philo->last_meal > ft_get_rules()->time_to_die)
	{
		pthread_mutex_unlock(&ft_get_mutex()->meals_verification);
		return (1);
	}
	pthread_mutex_unlock(&ft_get_mutex()->meals_verification);
	return (0);
}