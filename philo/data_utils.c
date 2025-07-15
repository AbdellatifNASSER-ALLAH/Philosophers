/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 02:38:08 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/15 14:51:32 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	get_value(long *value, t_data *data)
{
	long	ret;

	pthread_mutex_lock(&data->mt_lock);
	ret = *value;
	pthread_mutex_unlock(&data->mt_lock);
	return (ret);
}

void	set_value(long value, long *to, t_data *data)
{
	pthread_mutex_lock(&data->mt_lock);
	*to = value;
	pthread_mutex_unlock(&data->mt_lock);
}

void	set_state(t_state st, t_philo *ph)
{
	pthread_mutex_lock(&ph->data->mt_lock);
	ph->st = st;
	pthread_mutex_unlock(&ph->data->mt_lock);
}

t_state	get_state(t_philo *ph)
{
	t_state	st;

	pthread_mutex_lock(&ph->data->mt_lock);
	st = ph->st;
	pthread_mutex_unlock(&ph->data->mt_lock);
	return (st);
}
