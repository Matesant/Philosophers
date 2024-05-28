/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:03:23 by matesant          #+#    #+#             */
/*   Updated: 2024/05/28 00:13:02 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_philo_sit_down(t_philo *philo);

void	ft_dinning_hall(t_philo *philo)
{
	int					id;
	t_dining_etiquette	*rules;

	id = 0;
	rules = ft_get_rules();
	rules->program_start_time = ft_get_ms();
	while (id < rules->numb_philo)
	{
		ft_philo_sit_down(&philo[id]);
		id++;
	}
	waitpid(-1, NULL, 0);
}

void	ft_philo_sit_down(t_philo *philo)
{
	philo->pid = fork();
	if (philo->pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	else if (philo->pid == 0)
	{
		ft_im_hungry(philo);
		exit(0);
	}
}
