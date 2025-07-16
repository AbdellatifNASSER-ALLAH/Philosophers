/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:11:46 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/16 11:55:12 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*start_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(100);
	while (!get_value(&ph->data->stop, ph->data))
	{
		if (FULL == get_state(ph))
			break ;
		eat_philo(ph);
		sleep_philo(ph);
		think_philo(ph);
	}
	return (NULL);
}
