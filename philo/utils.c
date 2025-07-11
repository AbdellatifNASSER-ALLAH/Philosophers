/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:38:53 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/08 23:14:22 by abdnasse         ###   ########.fr       */
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

void	err_exit(const char *error)
{
	printf(RED"\n	%s\n"RESET, error);
	exit(EXIT_FAILURE);
}
