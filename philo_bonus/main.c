/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:46:54 by matesant          #+#    #+#             */
/*   Updated: 2024/05/28 00:02:57 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print_philo(t_philo *philo)
{
	printf("philo id: %d\n", philo->id);
	printf("philo pid: %d\n", philo->pid);
	printf("philo last_meal: %lld\n", philo->last_meal);
	printf("philo eating_sessions: %d\n", philo->eating_sessions);
}

void	ft_print_rules(t_dining_etiquette *rules)
{
	printf("rules numb_philo: %d\n", rules->numb_philo);
	printf("rules time_to_die: %d\n", rules->time_to_die);
	printf("rules time_to_eat: %d\n", rules->time_to_eat);
	printf("rules time_to_sleep: %d\n", rules->time_to_sleep);
	printf("rules numb_must_eat: %d\n", rules->number_times_philo_must_eat);
}

int	main(int argc, char **argv)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	ft_validate_user_input(argc, argv);
	ft_set_tabble_manners(&rules, argv);
	ft_init_philos();
	ft_dinning_hall(rules->philosophers);
	return (0);
}

t_dining_etiquette	*ft_get_rules(void)
{
	static t_dining_etiquette	tabble_manners;

	return (&tabble_manners);
}
