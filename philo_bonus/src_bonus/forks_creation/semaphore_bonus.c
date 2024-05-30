/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:35:46 by matesant          #+#    #+#             */
/*   Updated: 2024/05/30 01:35:00 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_init_semaphore(void)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	sem_unlink("forks");
	sem_unlink("print");
	rules->print = sem_open("/print", O_CREAT | O_RDWR, 0644, 1);
	rules->forks = sem_open("/forks", O_CREAT | O_RDWR, 0644,
			rules->numb_philo);
}

void	ft_close_semaphore(void)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	sem_close(rules->print);
	sem_close(rules->forks);
	sem_unlink("/print");
	sem_unlink("/forks");
}
