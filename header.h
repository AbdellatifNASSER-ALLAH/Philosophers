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
# define MALLOC_ERR 1

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

//=== Data types
typedef enum e_status 
{
	THINK,
	SLEEP,
	EAT
}	t_status;


typedef struct s_data t_data;

typedef struct	s_philo
{
	t_data	*data;
	int	id;
	int	ate;
	int	dead;
	t_status	st;
}	t_philo;

typedef struct s_data
{
	int	nb_philos;
	int	tdie;
	int	teat;
	int	tsleep;
	int	nb_time_philo_must_eat;
	t_philo	**philo;
}		t_data;

//=== Parsing
void	ft_instructions(void);
int		parse(int ac, char **av, t_data *data);
long	ft_atoi(char *nb);

//=== Initialisation of the Data
int		init_data(t_data *data);

#endif
