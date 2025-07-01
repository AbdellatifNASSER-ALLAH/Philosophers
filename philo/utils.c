/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:38:53 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/08 23:14:22 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"
#include <pthread.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size && nmemb > SIZE_MAX / size)
		return (0);
	p = (unsigned char *)malloc(nmemb * size);
	if (!p)
		return (0);
	memset(p, 0, nmemb * size);
	return (p);
}

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	if (data->forks)
	{
		while (++i < data->nb_philos)
			pthread_mutex_destroy(&data->forks[i]);
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
	pthread_mutex_destroy(&data->mt_stop);
	pthread_mutex_destroy(&data->mt_print);
}

void	cleanup(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_join(data->philos[i].th, NULL);
	free_all(data);
}
