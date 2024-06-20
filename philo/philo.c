/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:04:11 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/20 11:56:39 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ll(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_data	data;

	atexit(ll);
	if (!init_data(&data, argv, argc))
		return (1);
	add_philos(&data);
	create_threads(&data);
	clear_program(&data);
	return (0);
}
