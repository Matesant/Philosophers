/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:06:23 by matesant          #+#    #+#             */
/*   Updated: 2024/05/19 12:47:43 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_tabble_manners(t_dining_etiquette *tabble_manners)
{
	printf("number_of_philosophers: %d\n", tabble_manners->numb_philo);
	printf("time_to_die: %d\n", tabble_manners->time_to_die);
	printf("time_to_eat: %d\n", tabble_manners->time_to_eat);
	printf("time_to_sleep: %d\n", tabble_manners->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat: %d\n",
		tabble_manners->number_times_philo_must_eat);
}

void	ft_print_philosophers(t_dining_etiquette *tabble_manners)
{
	int	id;

	id = 0;
	while (id < tabble_manners->numb_philo)
	{
		printf("-----------------------------------------------\n");
		printf("Philosopher %d\n", tabble_manners->philosophers[id].id);
		printf("left_fork: %d\n", tabble_manners->philosophers[id].left_fork);
		printf("right_fork: %d\n", tabble_manners->philosophers[id].right_fork);
		printf("-----------------------------------------------\n");
		id++;
	}
}

int	main(int argc, char **argv)
{
	t_dining_etiquette	*tabble_manners;

	tabble_manners = ft_get_rules();
	if (ft_validate_user_input(argc, argv) == TRUE)
		return (1);
	ft_set_tabble_manners(&tabble_manners, argv);
	ft_set_philosophers_rules(&tabble_manners);
	ft_init_fork_mutex();
	ft_philosophers_sit_down(&tabble_manners);
	return (0);
}

t_dining_etiquette	*ft_get_rules(void)
{
	static t_dining_etiquette	tabble_manners;

	return (&tabble_manners);
}
