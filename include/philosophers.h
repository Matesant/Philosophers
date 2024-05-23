/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:25:20 by matesant          #+#    #+#             */
/*   Updated: 2024/05/23 19:12:56 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define YELLOW "\001\033[1;33m\002"
# define GREEN "\001\033[1;32m\002"
# define RED "\001\033[1;31m\002"
# define BLUE "\001\033[1;94m\002"
# define PURPLE "\001\033[1;35m\002"
# define CYAN "\001\033[1;36m\002"
# define WHITE "\001\033[1;37m\002"
# define RESET "\001\033[0m\002"

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_mutex
{
	pthread_mutex_t	waiting_for_philo_take_fork;
	pthread_mutex_t	philo_dead_verification;
	pthread_mutex_t	meals_verification;
	pthread_mutex_t	write_rights;
	pthread_mutex_t	forks[200];
}					t_mutex;

typedef struct s_philo
{
	int				id;
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
	int				number_times_philo_must_eat;
	int				corpse;
	int				philos_finished_eating;
	long long		program_start_time;
	t_philo			philosophers[200];
}					t_dining_etiquette;

/*---------------------------GETTERS-----------------------------------------*/
t_dining_etiquette	*ft_get_rules(void);
t_mutex				*ft_get_mutex(void);
/*---------------------------------------------------------------------------*/

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

/*---------------------------MONITOR-----------------------------------------*/
void				ft_historian(void);
t_bool				ft_dead_or_alive(void);
t_bool				ft_is_dead(t_philo *philo);
t_bool				ft_completed_caloric_intake(t_dining_etiquette *rules);
t_bool				ft_there_is_a_corpse_on_table(t_philo *philo);
/*---------------------------------------------------------------------------*/

/*---------------------------ROUTINE-----------------------------------------*/
void				*ft_philosophers_arrive_for_dinner(void *void_philo);
void				*ft_alone_in_the_dark(void *void_philo);
/*---------------------------------------------------------------------------*/

/*---------------------------PRINT-------------------------------------------*/
void				ft_print_actions(t_philo *philo, char *action);
/*---------------------------------------------------------------------------*/

/*---------------------------TIMESTAMP---------------------------------------*/
long long			ft_return_time_of_day(void);
long long			ft_get_ms(void);
void				ft_activity_time(long long time);
/*---------------------------------------------------------------------------*/

/*---------------------------THREADS-----------------------------------------*/
int					ft_init_fork_mutex(void);
int					ft_philosophers_sit_down(t_dining_etiquette **rules);
/*---------------------------------------------------------------------------*/

/*---------------------------MEALS-------------------------------------------*/
t_bool				ft_eat_meal(t_philo *philo);
t_bool				ft_all_eaten(void);
/*---------------------------------------------------------------------------*/

/*---------------------------EXIT--------------------------------------------*/
void				ft_exit(void);
/*---------------------------------------------------------------------------*/

/*---------------------------UTILS-------------------------------------------*/
int					ft_how_many_finished(void);
/*---------------------------------------------------------------------------*/

#endif