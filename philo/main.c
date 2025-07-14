/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:26:44 by abdnasse          #+#    #+#             */
/*   Updated: 2025/07/14 09:42:13 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!parse(ac, av, &data))
		return (ft_instructions(), PARSE_ERR);
	init_data(&data);
	run_philos(data.philos);
	run_monitor(&data);
	cleanup(&data);
	return (0);
}
