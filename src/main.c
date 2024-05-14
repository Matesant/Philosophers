/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:06:23 by matesant          #+#    #+#             */
/*   Updated: 2024/05/07 16:07:08 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		min;

void	*faz_o_l()
{
	int	i;

	i = 0;
	while (i < 100000)
	{
		min++;
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;

	if (ft_validate_user_input(argc, argv) == TRUE)
		return (1);
	pthread_create(&t1, NULL, &faz_o_l, NULL);
	pthread_create(&t2, NULL, &faz_o_l, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("min: %d\n", min);
	return (0);
}
