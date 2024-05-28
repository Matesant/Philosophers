/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:35:46 by matesant          #+#    #+#             */
/*   Updated: 2024/05/28 13:59:01 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_semaphore(void)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	sem_unlink("forks");
	sem_unlink("print");
	rules->print = sem_open("print", O_CREAT | O_RDWR, 0644, 1);
	rules->forks = sem_open("/forks", O_CREAT | O_RDWR, 0644, rules->numb_philo);
}
