/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:43:19 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/17 17:37:26 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	philo_died(long now, t_philo ph);
static int	philos_full(t_philo *ph, long nb_philos);

void	run_monitor(t_data *data)
{
	pthread_t	th;

	if (pthread_create(&th, NULL, monitor_routine, data))
		print_err("pthread create monitor faild!");
	if (pthread_join(th, NULL))
		print_err("pthread join monitor faild!");
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	long	now;
	int		i;

	data = (t_data *)arg;
	while (!get_value(&data->stop, data))
	{
		i = -1;
		now = get_time();
		while (++i < data->nb_philos)
		{
			if (philo_died(now, data->philos[i]))
			{
				set_value(1, &data->stop, data);
				set_state(DEAD, &data->philos[i]);
				print_state(&data->philos[i]);
				return (NULL);
			}
		}
		if (data->nb_meals > 0 && philos_full(data->philos, data->nb_philos))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

static int	philos_full(t_philo *ph, long nb_philos)
{
	int	i;

	if (get_value(&ph->data->stop, ph->data))
		return (1);
	i = -1;
	while (++i < nb_philos)
		if (FULL != get_state(&ph[i]))
			return (0);
	set_value(1, &ph->data->stop, ph->data);
	pthread_mutex_lock(&ph->data->mt_print);
	printf("All philosophers are FULL\n");
	pthread_mutex_unlock(&ph->data->mt_print);
	return (1);
}

static int	philo_died(long now, t_philo ph)
{
	long	age;

	age = now - get_value(&ph.last_meal, ph.data);
	if (age > ph.data->tdie)
		return (1);
	return (0);
}
