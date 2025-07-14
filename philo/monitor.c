/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:43:19 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/14 15:38:10 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	long	philo_age(long	now, t_philo ph);
static	int	philos_full(t_philo *ph, long nb_philos);

void run_monitor(t_data *data)
{
	pthread_t	th;

	if (pthread_create(&th, NULL, monitor_routine, data))
		err_exit("pthread create monitor faild!");
	if (pthread_detach(th))
		err_exit("pthread detach monitor faild!");
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	long	now;
	int	i;

	data = (t_data *)arg;
	while (!get_value(&data->stop, data))
	{
		i = -1;
		now = get_time();
		while (++i < data->nb_philos)
			if (philo_age(now, data->philos[i]) > data->tdie)
			{
				set_value(1, &data->stop, data);
				set_state(DEAD, &data->philos[i]);
				print_state(&data->philos[i]);
				return (NULL);
			}
		if (data->nb_meals > 0 && philos_full(data->philos, data->nb_philos))
			return (NULL);
		usleep(1000);
	}
	return  (NULL);
}

static	int	philos_full(t_philo *ph, long nb_philos)
{
	int	 i;

	i = -1;
	while (++i < nb_philos)
		if (FULL != get_state(&ph[i]))
			return (0);
	print_state(ph);
	set_value(1, &ph->data->stop, ph->data);
	return (1);
}

static	long	philo_age(long	now, t_philo ph)
{
	long	last_meal;

	last_meal = get_value(&ph.last_meal, ph.data);
	return (now - last_meal);
}
