/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:02:53 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/08 11:57:04 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	add_philos(t_data *data)
{
	t_philo	philo;
	int		i;

	i = -1;
	data->program_start = current_time();
	while (++i < data->number_philos)
	{
		philo.id = i;
		philo.data = data;
		philo.is_dead = 0;
		philo.eat_nb = 0;
		philo.last_time_eat = data->program_start;
		data->philos[i] = philo;
		data->philos[i].r_fork
			= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	}
	i = -1;
	while (++i < data->number_philos)
	{
		if (i == data->number_philos - 1)
			data->philos[i].l_fork = data->philos[0].r_fork;
		else
			data->philos[i].l_fork = data->philos[i + 1].r_fork;
	}
	return (1);
}
