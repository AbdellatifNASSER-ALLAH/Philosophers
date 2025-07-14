/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:29:10 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/14 15:18:10 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_valid(char *n);

int	parse(int ac, char **av, t_data *data)
{
	int	i;

	if (!(ac > 4 && ac < 7))
		return (0);
	i = 0;
	while (++i < 5)
		if (ft_atoi(av[i]) <= 0)
			return (0);
	data->nb_philos = ft_atoi(av[1]);
	data->tdie = ft_atoi(av[2]);
	data->teat = ft_atoi(av[3]);
	data->tsleep = ft_atoi(av[4]);
	if (ac == 6 && ft_atoi(av[5]) < 0)
		return (0);
	data->nb_meals = ft_atoi(av[5]);
	data->start_time = get_time();
	return (1);
}

long	ft_atoi(char *nb)
{
	long	res;

	res = 0;
	if (!nb || !(*nb && *nb >= '0' && *nb <= '9') || is_valid(nb))
		return (-1);
	while (*nb && *nb >= '0' && *nb <= '9')
		res = res * 10 + (*nb++ - 48);
	if (*nb || res > 2147483647 || res < 0)
		return (-1);
	return (res);
}

static int	is_valid(char *n)
{
	int	len;

	len = 0;
	while (*n &&  *n == '0')
		n++;
	while (*n && *n >= '0' && *n <= '9')
	{
		len++;
		n++;
	}
	if (len > 10)
		return (1);
	return (0);
}

void	ft_instructions(void)
{
	write(2, RED "Error: Invalid arguments.\n" RESET, 37);
	write(2, "Instructions! The last one is optional:\n", 41);
	write(2, "Example: ./philo 5 800 200 200 [5]\n", 35);
	write(2, "  number_of_philosophers\n", 26);
	write(2, "  time_to_die\n", 14);
	write(2, "  time_to_eat\n", 14);
	write(2, "  time_to_sleep\n", 17);
	write(2, "  [number_of_times_each_philosopher_must_eat]\n", 47);
}
