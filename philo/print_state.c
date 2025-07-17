/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:25:10 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/17 14:09:18 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_state(t_philo *ph)
{
	char	*msg[6];
	t_state	st;
	long	time;

	pthread_mutex_lock(&ph->data->mt_print);
	msg[WAIT] = "has taken a fork";
	msg[THINK] = "is thinking";
	msg[SLEEP] = "is sleeping";
	msg[EAT] = "is eating";
	msg[DEAD] = "died";
	if (FULL == get_state(ph))
		return ;
	time = get_time() - get_value(&ph->data->start_time, ph->data);
	st = get_state(ph);
	if (st != DEAD && !get_value(&ph->data->stop, ph->data))
		printf("%ld %d %s\n", time, ph->id, msg[st]);
	else if (st == DEAD)
		printf("%ld %d %s\n", time, ph->id, msg[st]);
	pthread_mutex_unlock(&ph->data->mt_print);
}
