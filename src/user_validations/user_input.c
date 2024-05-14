/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:08:33 by matesant          #+#    #+#             */
/*   Updated: 2024/05/07 14:23:42 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_bool	ft_check_args(int argc);
static t_bool	ft_check_not_number(char **argv);

t_bool	ft_validate_user_input(int argc, char **argv)
{
	if (ft_check_args(argc) == TRUE)
		return (TRUE);
	if (ft_check_not_number(argv) == TRUE)
		return (TRUE);
	return (FALSE);
}

static t_bool	ft_check_args(int argc)
{
	if (argc != 5 && argc != 6)
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
