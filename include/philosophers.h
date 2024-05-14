/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:04:01 by matesant          #+#    #+#             */
/*   Updated: 2024/05/14 17:17:39 by matesant         ###   ########.fr       */
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
}		t_bool;

/*---------------------------USER-VALIDATIONS---------------------*/
t_bool	ft_validate_user_input(int argc, char **argv);
int		ft_isdigit(int c);
/*----------------------------------------------------------------*/

/*---------------------------UTILS--------------------------------*/
long	ft_atol(char *number_string);
/*----------------------------------------------------------------*/