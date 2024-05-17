/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:08:33 by matesant          #+#    #+#             */
/*   Updated: 2024/05/17 17:54:15 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_bool	ft_number_args(int argc);
static t_bool	ft_check_not_number(char **argv);
static t_bool	ft_valid_parameters(char **parameters);

t_bool	ft_validate_user_input(int argc, char **argv)
{
	if (ft_number_args(argc) == TRUE)
		return (TRUE);
	if (ft_check_not_number(argv) == TRUE)
		return (TRUE);
	if (ft_valid_parameters(argv) == TRUE)
		return (TRUE);
	return (FALSE);
}

static t_bool	ft_number_args(int user_input)
{
	if (user_input == 1)
	{
		printf(" How to use:\n ./philo\n [1][number_of_philosophers]\n");
		printf(" [2][time_to_die]\n [3][time_to_eat]\n");
		printf(" [4][time_to_sleep]\n");
		printf(" [5][number_of_times_each_philosopher_must_eat]\n");
		printf(" Example: ./philo 5 800 200 200\n");
		return (TRUE);
	}
	if (user_input != 5 && user_input != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	ft_check_not_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Error: arguments must be numbers\n");
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

static t_bool	ft_valid_parameters(char **parameters)
{
	int	miliseconds_input;

	if (ft_atol(parameters[1]) < 1 || ft_atol(parameters[1]) > 200)
	{
		printf("Error: number of philosophers must be between 1 and 200\n");
		return (TRUE);
	}
	miliseconds_input = 2;
	while (parameters[miliseconds_input])
	{
		if (ft_atol(parameters[miliseconds_input]) < 60)
		{
			printf("Error: time in parameter [%d] must be at least 60ms\n",
				miliseconds_input);
			return (TRUE);
		}
		miliseconds_input++;
	}
	return (FALSE);
}
