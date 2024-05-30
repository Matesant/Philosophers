/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_forks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:20:48 by matesant          #+#    #+#             */
/*   Updated: 2024/05/30 02:04:50 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_kill_philo_fork(t_dining_etiquette *rules)
{
	int	id;

	id = 0;
	while (id < rules->numb_philo)
	{
		kill(rules->philosophers[id].pid, SIGKILL);
		id++;
	}
}
