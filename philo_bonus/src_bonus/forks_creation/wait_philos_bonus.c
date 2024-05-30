/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:33:21 by matesant          #+#    #+#             */
/*   Updated: 2024/05/30 00:19:49 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_wait_philos(void)
{
	int					exit_status;
	int					id;
	t_dining_etiquette	*rules;

	id = 0;
	exit_status = EXIT_SUCCESS;
	rules = ft_get_rules();
	while (id < rules->numb_philo)
	{
		waitpid(0, &exit_status, 0);
		if (WIFEXITED(exit_status) && WEXITSTATUS(exit_status) == EXIT_FAILURE)
			break ;
		id++;
	}
	if (exit_status != EXIT_SUCCESS)
	{
		ft_kill_philo_fork(rules);
	}
}
