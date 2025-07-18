/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:38:33 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/19 12:01:44 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	lock_right(t_philo *p);
static	void	lock_left(t_philo *p);

void	grab_forks(t_philo *p)
{
	if (FULL == get_state(p) || DEAD == get_state(p))
		return ;
	if (p->left_f == p->right_f)
	{
		lock_left(p);
		while (!get_value(&p->data->stop, p->data))
			usleep(500);
		return ;
	}
	if (p->id % 2 == 0)
	{
		lock_right(p);
		lock_left(p);
	}
	else
	{
		lock_left(p);
		lock_right(p);
	}
	set_value(1, &p->has_forks, p->data);
	set_state(READY, p);
}

void	put_down_forks(t_philo *ph)
{
	if (ph->left_f == ph->right_f)
	{
		if (pthread_mutex_unlock(ph->left_f))
			print_err("Error: unlocking left fork failed!", ph->data);
		return ;
	}
	if (get_value(&ph->has_forks, ph->data))
	{
		if (pthread_mutex_unlock(ph->right_f))
			return (print_err("Error: unlocking right fork failed!", ph->data));
		if (pthread_mutex_unlock(ph->left_f))
			return (print_err("Error: unlocking left fork failed!", ph->data));
		set_value(0, &ph->has_forks, ph->data);
	}
}

static	void	lock_left(t_philo *p)
{
	if (pthread_mutex_lock(p->left_f))
		return (print_err("Error: mutex lock left fork faild!", p->data));
	set_state(WAIT, p);
	print_state(p);
}

static	void	lock_right(t_philo *p)
{
	if (pthread_mutex_lock(p->right_f))
		return (print_err("Error: mutex lock right fork faild!", p->data));
	set_state(WAIT, p);
	print_state(p);
}
