/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:06:23 by matesant          #+#    #+#             */
/*   Updated: 2024/05/16 14:13:01 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_print_tabble_manners(t_dining_etiquette *tabble_manners)
{
	printf("number_of_philosophers: %d\n", tabble_manners->number_of_philosophers);
	printf("time_to_die: %d\n", tabble_manners->time_to_die);
	printf("time_to_eat: %d\n", tabble_manners->time_to_eat);
	printf("time_to_sleep: %d\n", tabble_manners->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n", tabble_manners->number_of_times_each_philosopher_must_eat);
}

int	main(int argc, char **argv)
{
	t_dining_etiquette	tabble_manners;

	if (ft_validate_user_input(argc, argv) == TRUE)
		return (1);
	ft_set_tabble_manners(&tabble_manners, argv);
	ft_print_tabble_manners(&tabble_manners);

	return (0);
}
