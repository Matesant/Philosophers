/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:04:01 by matesant          #+#    #+#             */
/*   Updated: 2024/05/17 17:53:43 by matesant         ###   ########.fr       */
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
	int				numb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_times_philosophers_must_eat;
	pthread_mutex_t	forks[200];
	t_philo			philosophers[200];
}					t_dining_etiquette;

t_dining_etiquette	*ft_get_rules(void);

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
void				ft_set_philosophers_rules(void);
/*---------------------------------------------------------------------------*/