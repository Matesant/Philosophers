/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:06:58 by matesant          #+#    #+#             */
/*   Updated: 2024/05/23 19:25:26 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_philosophers_arrive_for_dinner(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (philo->id % 2 == 0)
		usleep(10000);
	while (!ft_dead_or_alive())
	{
		if (ft_all_eaten())
			break ;
		ft_eat_meal(philo);
		ft_print_actions(philo, PURPLE"😴 is sleeping"RESET);
		ft_activity_time(ft_get_rules()->time_to_sleep);
		ft_print_actions(philo, GREEN"🤔 is thinking"RESET);
		ft_activity_time(1);
	}
	return (NULL);
}

void	*ft_alone_in_the_dark(void *void_philo)
{
	t_philo			*philo;
	pthread_mutex_t	*forks;

	philo = (t_philo *)void_philo;
	forks = ft_get_mutex()->forks;
	pthread_mutex_lock(&forks[philo->left_fork]);
	ft_print_actions(philo, "has taken a fork");
	pthread_mutex_unlock(&forks[philo->left_fork]);
	return (NULL);
}
