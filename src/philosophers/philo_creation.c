/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:35:34 by matesant          #+#    #+#             */
/*   Updated: 2024/05/17 17:52:53 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_set_philosophers_rules(void)
{
	int					id;
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	id = rules->numb_philo;
	while (id <= 0)
	{
		rules->philosophers[id].id = id;
		rules->philosophers[id].left_fork = id;
		rules->philosophers[id].right_fork = (id + 1) % rules->numb_philo;
	}
}
