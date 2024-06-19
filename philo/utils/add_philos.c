/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:02:53 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/19 11:58:29 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	add_philos(t_data *data)
{
	t_philo	philo;
	int		i;

	i = 0;
	while (i < data->number_philos)
	{
		philo.id = i + 1;
		philo.data = data;
		pthread_mutex_init(&philo.last_eat_mutex, NULL);
		philo.eat_nb = 0;
		philo.r_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		philo.last_time_eat = current_time();
		data->philos[i] = philo;
		i++;
	}
	i = 0;
	while (i < data->number_philos)
	{
		if (i == data->number_philos - 1)
			data->philos[i].l_fork = data->philos[0].r_fork;
		else
			data->philos[i].l_fork = data->philos[i + 1].r_fork;
		i++;
	}
	return (1);
}
