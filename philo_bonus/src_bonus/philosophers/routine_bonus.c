/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:15:16 by matesant          #+#    #+#             */
/*   Updated: 2024/05/30 01:05:13 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_im_hungry(t_philo *philo)
{
	while (1)
	{
		ft_eat(philo);
		ft_print_actions(philo, "is sleeping");
		ft_sleep(philo);
		ft_print_actions(philo, "is thinking");
		while (*(int *)ft_get_rules()->forks < 2)
			ft_historian(philo);
	}
	return (NULL);
}
