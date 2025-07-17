/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:38:53 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/17 14:58:22 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size && nmemb > SIZE_MAX / size)
		err_exit("ft_calloc error ! size");
	p = (unsigned char *)malloc(nmemb * size);
	if (!p)
		err_exit("ft_calloc malloc error!");
	memset(p, 0, nmemb * size);
	return (p);
}

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		err_exit("gettimeofday error!");
	return (((long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sleep_time(t_philo *ph)
{
	long	start;
	long	duration;

	duration = 0;
	if (get_state(ph) == EAT)
		duration = get_value(&ph->data->teat, ph->data);
	else if (get_state(ph) == SLEEP)
		duration = get_value(&ph->data->tsleep, ph->data);
	start = get_time();
	while ((get_time() - start) < duration && !get_value(&ph->data->stop,
			ph->data))
		usleep(500);
}

void	err_exit(const char *error)
{
	printf(RED "\n	%s\n" RESET, error);
	exit(EXIT_FAILURE);
}
