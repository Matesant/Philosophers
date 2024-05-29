/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:08:33 by matesant          #+#    #+#             */
/*   Updated: 2024/05/29 19:15:43 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static t_bool	ft_number_args(int argc);
static t_bool	ft_check_not_number(char **argv);
static t_bool	ft_valid_parameters(char **parameters);
static t_bool	ft_check_number_of_meals(char **parameters);

t_bool	ft_validate_user_input(int argc, char **argv)
{
	if (ft_number_args(argc) == TRUE)
		return (TRUE);
	if (ft_check_not_number(argv) == TRUE)
		return (TRUE);
	if (ft_valid_parameters(argv) == TRUE)
		return (TRUE);
	ft_check_number_of_meals(argv);
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
	int	parameter;
	int	ascii;

	parameter = 1;
	while (argv[parameter])
	{
		ascii = 0;
		while (argv[parameter][ascii])
		{
			if (!ft_isdigit(argv[parameter][ascii]))
			{
				printf("Error: arguments must be numbers\n");
				return (TRUE);
			}
			ascii++;
		}
		parameter++;
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
		if (ft_atol(parameters[miliseconds_input]) < 60
			&& miliseconds_input != 5)
		{
			printf("Error: time in parameter [%d] must be at least 60ms\n",
				miliseconds_input);
			return (TRUE);
		}
		miliseconds_input++;
	}
	return (FALSE);
}

static t_bool	ft_check_number_of_meals(char **parameters)
{
	if (parameters[5] && ft_atol(parameters[5]) < 1)
	{
		printf("Error: number of meals must be at least 1\n");
		return (TRUE);
	}
	if (!parameters[5])
		parameters[5] = "-1";
	return (FALSE);
}
