/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:46:54 by matesant          #+#    #+#             */
/*   Updated: 2024/05/27 17:10:34 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t				*g_sem;

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
	static t_dining_etiquette tabble_manners;

	return (&tabble_manners);
}