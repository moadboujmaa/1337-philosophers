/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:04:11 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/28 15:33:58 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	watcher(t_data *data)
// {
// 	(void) data;
// 	while (1)
// 	{
// 		printf("moadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoadmoad\n");
// 	}
// }

int	main(int argc, char **argv)
{
	t_data	data;

	if (!init_data(&data, argv, argc))
		return (1);
	add_philos(&data);
	create_threads(&data);
	watcher(&data);
	return (0);
}
