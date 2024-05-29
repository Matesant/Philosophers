/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:39:17 by matesant          #+#    #+#             */
/*   Updated: 2024/05/29 19:15:20 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_print_actions(t_philo *philo, char *action)
{
	printf("\033[1;37m%lld\033[0m %d %s\n", ft_get_ms(), philo->id, action);
}
