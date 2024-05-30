/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:46:08 by matesant          #+#    #+#             */
/*   Updated: 2024/05/30 01:05:54 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
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

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	int				eating_sessions;
	pid_t			pid;
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
	sem_t			*forks;
	sem_t			*print;
}					t_dining_etiquette;

void				ft_set_tabble_manners(t_dining_etiquette **tabble_manners,
						char **argv);
t_bool				ft_activity_time(long long time, t_philo *philo);
long long			ft_get_ms(void);
long long			ft_return_time_of_day(void);
int					ft_isdigit(int c);
t_bool				ft_validate_user_input(int argc, char **argv);
long				ft_atol(char *number_string);
t_dining_etiquette	*ft_get_rules(void);
void				ft_init_philos(void);
void				ft_dinning_hall(t_philo *philo);
void				*ft_im_hungry(t_philo *philo);
void				ft_eat(t_philo *philo);
void				ft_init_semaphore(void);
t_bool				ft_historian(t_philo *philo);
void				ft_wait_philos(void);
void				ft_kill_philo_fork(t_dining_etiquette *rules);
void				ft_sleep(t_philo *philo);

/*-------------------------PRINT---------------------*/
void				ft_print_actions(t_philo *philo, char *action);
/*-------------------------UTILS---------------------*/

#endif