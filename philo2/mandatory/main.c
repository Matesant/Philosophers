/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:06:23 by matesant          #+#    #+#             */
/*   Updated: 2024/05/23 13:29:55 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_dining_etiquette	*tabble_manners;

	tabble_manners = ft_get_rules();
	if (ft_validate_user_input(argc, argv) == TRUE)
		return (1);
	ft_set_tabble_manners(&tabble_manners, argv);
	ft_set_philosophers_rules(&tabble_manners);
	if (ft_init_fork_mutex())
		return (1);
	if (ft_philosophers_sit_down(&tabble_manners))
		return (1);
	ft_exit();
	return (0);
}

t_dining_etiquette	*ft_get_rules(void)
{
	static t_dining_etiquette	tabble_manners;

	return (&tabble_manners);
}

t_mutex	*ft_get_mutex(void)
{
	static t_mutex	mutex;

	return (&mutex);
}
