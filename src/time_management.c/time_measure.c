/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_measure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:49:05 by matesant          #+#    #+#             */
/*   Updated: 2024/05/19 17:05:22 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_clock(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_get_ms(void)
{
	return (ft_clock() - ft_get_rules()->program_start_time);
}

void	ft_activity_time(long long time)
{
	usleep(time * 1000);
}
