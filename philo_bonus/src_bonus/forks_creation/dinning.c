/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:03:23 by matesant          #+#    #+#             */
/*   Updated: 2024/05/27 22:14:43 by matesant         ###   ########.fr       */
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
	while (id < rules->numb_philo)
	{
		ft_philo_sit_down(&philo[id]);
	}
	waitpid(-1, NULL, 0);
}

void	ft_philo_sit_down(t_philo *philo)
{
	philo->pid = fork();
	if (philo->pid == 0)
	{
		ft_im_hungry(philo);
		exit(0);
	}
	else
	{
		printf("Error: fork failed\n");
		exit(1);
	}
}
