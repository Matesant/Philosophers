/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:46:54 by matesant          #+#    #+#             */
/*   Updated: 2024/05/29 19:16:05 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_dining_etiquette	*rules;

	rules = ft_get_rules();
	if (ft_validate_user_input(argc, argv))
		return (1);
	ft_set_tabble_manners(&rules, argv);
	ft_init_philos();
	ft_init_semaphore();
	ft_dinning_hall(rules->philosophers);
	ft_wait_philos();
	sem_close(rules->print);
	sem_close(rules->forks);
	sem_unlink("/print");
	sem_unlink("/forks");
	return (0);
}

t_dining_etiquette	*ft_get_rules(void)
{
	static t_dining_etiquette	tabble_manners;

	return (&tabble_manners);
}
