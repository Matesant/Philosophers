/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabble_manners.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:02:46 by matesant          #+#    #+#             */
/*   Updated: 2024/05/17 17:48:50 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_set_tabble_manners(t_dining_etiquette *tabble_manners, char **argv)
{
	tabble_manners->numb_philo = ft_atol(argv[1]);
	tabble_manners->time_to_die = ft_atol(argv[2]);
	tabble_manners->time_to_eat = ft_atol(argv[3]);
	tabble_manners->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		tabble_manners->number_times_philosophers_must_eat = ft_atol(argv[5]);
	else
		tabble_manners->number_times_philosophers_must_eat = -1;
}
