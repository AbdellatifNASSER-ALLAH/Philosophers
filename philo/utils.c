/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:38:53 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/19 12:06:07 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size && nmemb > SIZE_MAX / size)
		return (print_err("ft_calloc error ! size", NULL), NULL);
	p = (unsigned char *)malloc(nmemb * size);
	if (!p)
		return (print_err("ft_calloc malloc faild !", NULL), NULL);
	memset(p, 0, nmemb * size);
	return (p);
}

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (print_err("gettimeofday error!", NULL), -1);
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

void	print_err(const char *error, t_data *data)
{
	if (data)
		set_value(2, &data->stop, data);
	printf(RED "\n	%s\n" RESET, error);
}
