/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:29:30 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/14 16:03:11 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	init_data(t_data *data)
{
	data->stop = 0;
	mutex_init(&data->mt_print);
	mutex_init(&data->mt_lock);
	init_forks(data);
	init_philos(data);
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = ft_calloc(sizeof(pthread_mutex_t), data->nb_philos);
	i = -1;
	while (++i < data->nb_philos)
		mutex_init(&data->forks[i]);
	return (0);
}

int	init_philos(t_data *data)
{
	pthread_mutex_t	*f;
	int		i;

	data->philos = ft_calloc(sizeof(t_philo), data->nb_philos);
	f = data->forks;
	i = -1;
	while (++i < data->nb_philos)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].nb_ate = 0;
		data->philos[i].st = WAIT;
		data->philos[i].left_f = &f[i];
		if (i < data->nb_philos - 1)
			data->philos[i].right_f = &f[i + 1];
		else if (data->nb_philos >= 1)
			data->philos[i].right_f = &f[0];
	}
	return (0);
}

void	run_philos(t_philo *p)
{
	int	i;

	set_value(get_time(), &p->data->start_time, p->data);
	i = -1;
	while(++i < p->data->nb_philos)
		create_philo(&p[i]);
}
