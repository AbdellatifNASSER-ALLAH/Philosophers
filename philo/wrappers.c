/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:03:58 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/19 12:04:06 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mutex_init(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL))
		return (print_err("mutex init failed !", NULL));
}

void	create_philo(t_philo *p)
{
	p->last_meal = get_time();
	if (pthread_create(&p->th, NULL, start_routine, p))
		return (print_err("pthread_create philo failed !", NULL));
}
