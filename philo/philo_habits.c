/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_habits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:34:30 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/13 02:18:59 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	eat_philo(t_philo *ph)
{
	set_state(EAT, ph);
	set_value(get_time(), &ph->last_meal, ph->data);
	print_state(ph);
	sleep_time(ph);
	set_value(ph->nb_ate + 1, &ph->nb_ate, ph->data);
}

void	sleep_philo(t_philo *ph)
{
	set_state(SLEEP, ph);
	print_state(ph);
	sleep_time(ph);
}

void	think_philo(t_philo *ph)
{
	set_state(THINK, ph);
	print_state(ph);
}
