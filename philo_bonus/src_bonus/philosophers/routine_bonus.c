/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:15:16 by matesant          #+#    #+#             */
/*   Updated: 2024/05/30 02:00:29 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_im_hungry(t_philo *philo)
{
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_thinking(philo);
	}
	return (NULL);
}
