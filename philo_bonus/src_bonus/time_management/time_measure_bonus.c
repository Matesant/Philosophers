/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_measure_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:49:05 by matesant          #+#    #+#             */
/*   Updated: 2024/05/29 19:15:39 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

t_bool	ft_activity_time(long long time, t_philo *philo)
{
	long long	current_time;

	current_time = ft_get_ms();
	while (ft_get_ms() - current_time < time)
	{
		usleep(10);
		if (ft_historian(philo))
			return (1);
	}
	return (0);
}
