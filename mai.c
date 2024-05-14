/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mai.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:56:47 by matesant          #+#    #+#             */
/*   Updated: 2024/05/14 13:24:06 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int				prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
pthread_mutex_t	mutex;

void	*faz_o_l(void *ints)
{
	int	store;

	store = *(int *)ints;
	printf("Thread %d,", prime[store]);
	free(ints);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	t1[9];
	int			i;
	int			*store;

	i = -1;
	pthread_mutex_init(&mutex, NULL);
	while (++i <= 9)
	{
		store = malloc(sizeof(int));
		*store = i;
		pthread_create(&t1[i], NULL, &faz_o_l, store);
	}
	i = -1;
	while (++i <= 9)
		pthread_join(t1[i], NULL);
	pthread_mutex_destroy(&mutex);
	return (0);
}
