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

int	init_data(t_data *data)
{
	if (pthread_mutex_init(&data->mt_print, NULL))
		return (MUTEX_ERR);
	if (pthread_mutex_init(&data->mt_stop, NULL))
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
	return (0);
}

int	init_philos(t_data *data)
{
	t_philo			*p;
	pthread_mutex_t	*f;
	int				i;

	p = data->philos;
	p = ft_calloc(sizeof(t_philo), data->nb_philos);
	if (p == NULL)
		return (PHILO_ERR);
	f = data->forks;
	i = -1;
	while (++i < data->nb_philos)
	{
		p[i].data = data;
		p[i].id = i + 1;
		p[i].nb_ate = 0;
		p[i].st = WAIT;
		p[i].left_f = &f[i];
		if (i < data->nb_philos - 1)
			p[i].right_f = &f[i + 1];
		else if (data->nb_philos > 1)
			p[i].right_f = &f[0];
	}
	return (0);
}
