/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:03:58 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/13 02:08:31 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mutex_init(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL))
		err_exit("mutex init failed !");
}

void	create_philo(t_philo *p)
{
	if (pthread_create(&p->th, NULL, start_routine, p))
		err_exit("pthread_create failed !");
}

