/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:15:16 by matesant          #+#    #+#             */
/*   Updated: 2024/05/29 19:15:23 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_im_hungry(t_philo *philo)
{
	int					i;
	t_dining_etiquette	*rules;

	i = 0;
	rules = ft_get_rules();
	while (i < 5)
	{
		ft_eat(philo);
		ft_print_actions(philo, "is sleeping");
		if (ft_activity_time(rules->time_to_sleep, philo))
		{
			printf("%lld %d died\n", ft_get_ms(), philo->id);
			exit(EXIT_FAILURE);
		}
		ft_print_actions(philo, "is thinking");
		usleep(1000);
		i++;
	}
}
