/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:15:16 by matesant          #+#    #+#             */
/*   Updated: 2024/05/28 00:14:18 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		ft_activity_time(rules->time_to_sleep);
		ft_print_actions(philo, "is thinking");
		ft_activity_time(1);
		i++;
	}
}
