/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mai.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:56:59 by matesant          #+#    #+#             */
/*   Updated: 2024/05/28 15:13:02 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

void *ft_oi(void *arg)
{
	while (1)
	{
		printf("Oi\n");
		sleep(1);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, ft_oi, NULL);
	while (1)
	{
		printf("I'm alive\n");
		sleep(1);
	}
	pthread_join(thread, NULL);
	return (0);
}
