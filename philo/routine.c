/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:11:46 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/01 14:11:48 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <pthread.h>

void	*start_routine(void *arg)
{
	t_philo	ph;

	ph = *(t_philo *)arg;
	//while (true)
		//if eat(philo)
		//else if sleep(philo)
		//else if think(philo)
		//else brea;
	return (NULL);
}

/*int	eat(t_philo ph)
{
	//if grap_phorks
	//	eating
	//esle 
	//	return 1;
}*/
