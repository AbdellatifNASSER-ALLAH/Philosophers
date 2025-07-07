/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:11:46 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/07 15:15:16 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	wait_threads(t_philo p)
{
	while (get_value(&p.data->stop, p.data))
		;
	set_value(get_time(), &p.data->start_time, p.data);
}

void	the_table(t_data *data)
{	
	run_philos(data->philos);
}

void	*start_routine(void *arg)
{
	t_philo	ph;

	ph = *(t_philo *)arg;
	wait_threads(ph);
	while(1)
	{
		grap_forks(ph);
	}
	return (NULL);
}
