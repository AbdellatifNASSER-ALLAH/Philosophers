/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_habits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:34:30 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/16 11:55:00 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	eat_philo(t_philo *ph)
{
	grab_forks(ph);
	if (FULL == get_state(ph) || READY != get_state(ph))
		return ;
	set_state(EAT, ph);
	set_value(get_time(), &ph->last_meal, ph->data);
	print_state(ph);
	sleep_time(ph);
	set_value(ph->nb_ate + 1, &ph->nb_ate, ph->data);
	if (get_value(&ph->nb_ate, ph->data) >= ph->data->nb_meals)
		set_state(FULL, ph);
	put_down_forks(ph);
}

void	sleep_philo(t_philo *ph)
{
	if (FULL == get_state(ph))
		return ;
	set_state(SLEEP, ph);
	print_state(ph);
	sleep_time(ph);
}

void	think_philo(t_philo *ph)
{
	if (FULL == get_state(ph))
		return ;
	set_state(THINK, ph);
	print_state(ph);
}
