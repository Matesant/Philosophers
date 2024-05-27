/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_measure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:49:05 by matesant          #+#    #+#             */
/*   Updated: 2024/05/27 14:25:56 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	usleep(time * 1000);
}

