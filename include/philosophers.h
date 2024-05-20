/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:12:16 by matesant          #+#    #+#             */
/*   Updated: 2024/05/19 21:31:00 by matesant         ###   ########.fr       */
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
	long long		last_meal;
	int				eating_sessions;
	pthread_t		philo_action;
}					t_philo;

typedef struct s_dining_etiquette
{
	int				numb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				corpse;
	int				number_times_philo_must_eat;
	long long		program_start_time;
	pthread_mutex_t	forks[199];
	pthread_mutex_t	waiting_for_philo_take_fork;
	pthread_mutex_t	write_rights;
	t_philo			philosophers[199];
}					t_dining_etiquette;

t_dining_etiquette	*ft_get_rules(void);
int					ft_philosophers_sit_down(t_dining_etiquette **rules);
void				ft_eat_meal(t_philo *philo);
int					ft_init_fork_mutex(void);
long long			ft_clock(void);
long long			ft_get_ms(void);
void				ft_activity_time(long long time);
void				ft_historian(void);
void				ft_print_actions(t_philo *philo, char *action);

/*---------------------------USER-VALIDATIONS--------------------------------*/
t_bool				ft_validate_user_input(int argc, char **argv);
int					ft_isdigit(int c);
/*---------------------------------------------------------------------------*/

/*---------------------------UTILS-------------------------------------------*/
long				ft_atol(char *number_string);
/*---------------------------------------------------------------------------*/

/*---------------------------PHILOSOPHERS-RULES------------------------------*/
void				ft_set_tabble_manners(t_dining_etiquette **tabble_manners,
						char **argv);
void				ft_set_philosophers_rules(t_dining_etiquette **rules);
/*---------------------------------------------------------------------------*/