/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:03:18 by matesant          #+#    #+#             */
/*   Updated: 2024/05/22 18:21:57 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_historian(void)
{
	int					philo_id;
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	while (1)
	{
		philo_id = 0;
		while ((philo_id < ft_get_rules()->numb_philo))
		{
			if (ft_there_is_a_corpse_on_table(&rules->philosophers[philo_id]))
				return ;
			if ((ft_completed_caloric_intake(rules)))
				return ;
			philo_id++;
		}
	}
}
