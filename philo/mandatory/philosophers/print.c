/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:39:17 by matesant          #+#    #+#             */
/*   Updated: 2024/05/23 19:20:22 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_actions(t_philo *philo, char *action)
{
	if (!ft_dead_or_alive())
	{
		pthread_mutex_lock(&ft_get_mutex()->write_rights);
		printf("\033[1;37m%lld\033[0m %d %s\n", ft_get_ms(), philo->id, action);
		pthread_mutex_unlock(&ft_get_mutex()->write_rights);
	}
}
