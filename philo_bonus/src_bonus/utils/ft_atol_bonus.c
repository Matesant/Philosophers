/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:14:11 by matesant          #+#    #+#             */
/*   Updated: 2024/05/29 19:15:47 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

long	ft_atol(char *number_string)
{
	long	number_ascii;
	int		actual_char;
	int		positive_negative;

	actual_char = 0;
	number_ascii = 0;
	positive_negative = 1;
	if (!number_string)
		return (-1);
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
