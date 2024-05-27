/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:14:11 by matesant          #+#    #+#             */
/*   Updated: 2024/05/27 14:26:11 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_atol(char *number_string)
{
	long	number_ascii;
	int		actual_char;
	int		positive_negative;

	actual_char = 0;
	number_ascii = 0;
	positive_negative = 1;
	if (number_string[actual_char] == '-')
	{
		positive_negative = -1;
		actual_char++;
	}
	while (number_string[actual_char])
	{
		number_ascii = number_ascii * 10 + number_string[actual_char] - '0';
		actual_char++;
	}
	return (number_ascii * positive_negative);
}
