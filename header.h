/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:29:35 by abdnasse          #+#    #+#             */
/*   Updated: 2025/06/20 02:29:48 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

// Macros
# define PARSE_ERR 1
# define MALLOC_ERR 2

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
//# include <time.h>

//=== Data types
typedef enum e_state 
{
	THINK,
	SLEEP,
	EAT,
	DEAD
}	t_state;


typedef struct s_data t_data;

typedef struct	s_philo
{
	int	id;
	int	nb_ate;
	pthread_mutex_t	mt_nb_ate;
	t_state	st;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	t_data	*data;
}	t_philo;

typedef struct s_data
{
	time_t	start_time;
	int	nb_philos;
	int	tdie;
	int	teat;
	int	tsleep;
	int	nb_meals;
	pthread_mutex_t	mt_nb_meals;
	t_philo	*philos;
	pthread_mutex_t	*forks;
}		t_data;

//=== Parsing
void	ft_instructions(void);
int		parse(int ac, char **av, t_data *data);
long	ft_atoi(char *nb);

//=== Initialisation of the Data
int		init_data(t_data *data);

#endif
