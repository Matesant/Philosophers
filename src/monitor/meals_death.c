/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:25:13 by matesant          #+#    #+#             */
/*   Updated: 2024/05/22 16:04:40 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_how_many_finished(void)
{
	int		how_many_philos_finished;
	t_philo	*philo;
	int		id;

	how_many_philos_finished = 0;
	id = 0;
	while (id <= ft_get_rules()->numb_philo)
	{
		philo = &ft_get_rules()->philosophers[id];
		pthread_mutex_lock(&ft_get_mutex()->meals_verification);
		if (philo->eating_sessions >= ft_get_rules()->numb_philo)
			how_many_philos_finished++;
		pthread_mutex_unlock(&ft_get_mutex()->meals_verification);
		id++;
	}
	printf("how many finished: %d\n", how_many_philos_finished);
	return (how_many_philos_finished);
}
