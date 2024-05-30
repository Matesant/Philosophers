/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 02:00:55 by matesant          #+#    #+#             */
/*   Updated: 2024/05/30 02:01:53 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_thinking(t_philo *philo)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	ft_print_actions(philo, GREEN "is thinking" RESET);
	while (*(int *)rules->forks < 2)
		ft_historian(philo);
}
