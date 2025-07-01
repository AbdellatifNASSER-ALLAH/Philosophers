/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:29:30 by abdnasse          #+#    #+#             */
/*   Updated: 2025/06/25 16:29:32 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <pthread.h>

int	init_data(t_data *data)
{
	if (pthread_mutex_init(&data->mt_nb_meals, NULL))
		return (MUTEX_ERR);
	if (init_forks(data))
		return (free_all(data), FORK_ERR);
	if (init_philos(data))
		return (free_all(data), PHILO_ERR);
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = ft_calloc(sizeof(pthread_mutex_t), data->nb_philos);
	if (!data->forks)
		return (FORK_ERR);
	i = -1;
	while (++i < data->nb_philos)
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (MUTEX_ERR);
}
