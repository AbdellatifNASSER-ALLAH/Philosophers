/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:29:10 by abdnasse          #+#    #+#             */
/*   Updated: 2025/06/20 02:29:15 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	parse(int ac, char **av, t_data *data)
{
	int	check;

	if (!(ac > 4 && ac < 7))
		return (0);
	check = ft_atoi(av[1]) * ft_atoi(av[2]) * ft_atoi(av[3]) * ft_atoi(av[4]);
	if (check <= 0)
		return (write(2, "Unexpected value!\n", 18), 0);
	data->nb_philos = ft_atoi(av[1]);
	data->tdie = ft_atoi(av[2]);
	data->teat = ft_atoi(av[3]);
	data->tsleep = ft_atoi(av[4]);
	if (ac == 6 && ft_atoi(av[5]) < 0)
		return (write(2, "Unexpected value!\n", 18), 0);
	if (ac == 6)
		data->nb_time_philo_must_eat = ft_atoi(av[5]);
	return (1);
}

long	ft_atoi(char *nb)
{
	long	res;

	res = 0;
	if (!(*nb && *nb >= '0' && *nb <= '9'))
		return (-1);
	while (*nb && *nb >= '0' && *nb <= '9')
		res = res * 10 + (*nb++ - 48);
	if (*nb || res > 2147483647 || res < 0)
		return (-1);
	return (res);
}

void	ft_instructions(void)
{
	write(2, "Instructions ! the last one is optional\n", 40);
	write(2, "number_of_philosophers", 22);
	write(2, " time_to_die", 12);
	write(2, " time_to_eat", 12);
	write(2, " time_to_sleep", 13);
	write(2, " [number_of_times_each_philosopher_must_eat] \n", 46);
}
