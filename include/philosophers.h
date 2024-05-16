/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:04:01 by matesant          #+#    #+#             */
/*   Updated: 2024/05/16 14:11:53 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_philo
{
	int				id;
	int				meals;
	int				left_fork;
	int				right_fork;
	struct timeval	last_meal;
	pthread_t		philosopher_activity;
}					t_philo;
typedef struct s_dining_etiquette
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	forks[200];
	t_philo			philosophers[200];
}					t_dining_etiquette;

/*---------------------------USER-VALIDATIONS--------------------------------*/
t_bool				ft_validate_user_input(int argc, char **argv);
int					ft_isdigit(int c);
/*---------------------------------------------------------------------------*/

/*---------------------------UTILS-------------------------------------------*/
long				ft_atol(char *number_string);
/*---------------------------------------------------------------------------*/

/*---------------------------PHILOSOPHERS-RULES------------------------------*/
void				ft_set_tabble_manners(t_dining_etiquette *tabble_manners,
						char **argv);
/*---------------------------------------------------------------------------*/