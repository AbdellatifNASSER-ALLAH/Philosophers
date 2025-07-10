/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:29:35 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/10 13:46:15 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#define RED     "\033[1;31m"
#define RESET   "\033[0m"
// Macros
# define PARSE_ERR 1
# define MALLOC_ERR 2
# define MUTEX_ERR 3
# define FORK_ERR 4
# define PHILO_ERR 5
# define THREAD_ERR 6

# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

//=== Data types
typedef enum e_state
{
	WAIT,
	THINK,
	SLEEP,
	EAT,
	DEAD
}	t_state;

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t	th;
	int	id;
	int	nb_ate;
	t_state	st;
	long	last_meal;
	pthread_mutex_t		*left_f;
	pthread_mutex_t		*right_f;
	t_data			*data;
}				t_philo;

typedef struct s_data
{
	long	start_time;
	long	nb_philos;
	long	tdie;
	long	teat;
	long	tsleep;
	long	nb_meals;
	long	stop;
	pthread_mutex_t	mt_lock;
	pthread_mutex_t	mt_print;
	t_philo	*philos;
	pthread_mutex_t	*forks;
}	t_data;

//=== data Utils
long	get_value(long *value, t_data *data);
void	set_value(long value, long *to, t_data *data);

//=== Helpers
void	grap_forks(t_philo p);

//=== Wrappers
void	mutex_init(pthread_mutex_t *mutex);
void	create_philo(t_philo p);

//=== Parsing
void	ft_instructions(void);
int	parse(int ac, char **av, t_data *data);
long	ft_atoi(char *nb);

//=== Initialisation of the Data
int	init_data(t_data *data);
int	init_forks(t_data *data);
int	init_philos(t_data *data);
void	run_philos(t_philo *p);

//=== The dining 
void	*start_routine(void *arg);

//=== Cleaning up
long	get_time(void);
void	cleanup(t_data *data);

//=== Utils
void	free_all(t_data *data);
void	*ft_calloc(size_t nmemb, size_t size); void	err_exit(const char *error);

#endif
