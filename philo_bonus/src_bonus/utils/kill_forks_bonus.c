/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_forks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:20:48 by matesant          #+#    #+#             */
/*   Updated: 2024/05/29 19:15:50 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_kill_philo_fork(t_dining_etiquette *rules)
{
	int	i;

	i = 0;
	while (i < rules->numb_philo)
	{
		kill(rules->philosophers[i].pid, SIGKILL);
		i++;
	}
}
