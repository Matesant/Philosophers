/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabble_manners.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:02:46 by matesant          #+#    #+#             */
/*   Updated: 2024/05/16 14:04:06 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_set_tabble_manners(t_dining_etiquette *tabble_manners, char **argv)
{
	tabble_manners->number_of_philosophers = ft_atol(argv[1]);
	tabble_manners->time_to_die = ft_atol(argv[2]);
	tabble_manners->time_to_eat = ft_atol(argv[3]);
	tabble_manners->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		tabble_manners->number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	else
		tabble_manners->number_of_times_each_philosopher_must_eat = -1;
}