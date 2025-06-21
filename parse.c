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

int	parse(int ac, char **av)
{
	(void)av;
	if (!(ac > 4 && ac < 7))
		return (write(2, "error parsing\n", 14), 0);
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
