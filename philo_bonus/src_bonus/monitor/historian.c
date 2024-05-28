/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:50:26 by matesant          #+#    #+#             */
/*   Updated: 2024/05/28 18:30:22 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	ft_corpse_on_table(void);
t_bool	ft_is_dead(t_philo *philo);

t_bool	ft_historian(t_philo *philo)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	if (ft_is_dead(philo))
		return (1);
	return (0);
}

t_bool	ft_is_dead(t_philo *philo)
{
	t_dining_etiquette	*rules;
	long long			current_time;

	rules = ft_get_rules();
	current_time = ft_get_ms();
	if (current_time - philo->last_meal > rules->time_to_die)
		return (1);
	return (0);
}

t_bool	ft_corpse_on_table(void)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	if (rules->corpse)
		return (1);
	return (0);
}
