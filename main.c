/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:26:44 by abdnasse          #+#    #+#             */
/*   Updated: 2025/06/20 02:26:46 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!parse(ac, av, &data))
	{
		ft_instructions();
		return (1);
	}
	if (init_data(&data))
		return (MALLOC_ERR);
	return (0);
}
