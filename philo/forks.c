/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:38:33 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/10 13:16:02 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	lock_rghit(t_philo p);
static	void	lock_lift(t_philo p);
static	void	has_taken_fork(t_philo p);
void	grap_forks(t_philo p)
{
	if (p.id % 2 == 0)
	{
		lock_rghit(p);
	 	lock_lift(p);
	}
	else
	{
	 	lock_lift(p);
		lock_rghit(p);
	}
}

static	void	lock_lift(t_philo p)
{
	if (pthread_mutex_lock(p.left_f))
		err_exit("Error: mutex lock left fork faild!");
	has_taken_fork(p);
}

static	void	lock_rghit(t_philo p)
{
	if (pthread_mutex_lock(p.right_f))
		err_exit("Error: mutex lock right fork faild!");
	has_taken_fork(p);
}

static	void	has_taken_fork(t_philo p)
{
	pthread_mutex_t	*lock;
	long	start_time;
	
	lock = &p.data->mt_lock;
	if (pthread_mutex_lock(lock))
		err_exit("Error: mutex lock left fork faild!");
	start_time = p.data->start_time;
	printf("%ld %d had taken a fork\n", get_time() - start_time, p.id);
	if (pthread_mutex_unlock(lock))
		err_exit("Error: mutex lock left fork faild!");
}
