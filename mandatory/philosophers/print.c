/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:39:17 by matesant          #+#    #+#             */
/*   Updated: 2024/05/22 13:27:51 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_actions(t_philo *philo, char *action)
{
	if (!ft_dead_or_alive())
	{
		pthread_mutex_lock(&ft_get_rules()->write_rights);
		printf("%lld %d %s\n", ft_get_ms(), philo->id, action);
		pthread_mutex_unlock(&ft_get_rules()->write_rights);
	}
}