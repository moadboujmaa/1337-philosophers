/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:58:37 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/19 12:02:28 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_death(t_data *data, int index)
{
	pthread_mutex_lock(&(data->philos[index].last_eat_mutex));
	if (current_time() - data->philos[index].last_time_eat >= data->time2die)
	{
		pthread_mutex_unlock(&(data->philos[index].last_eat_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(data->philos[index].last_eat_mutex));
	return (0);
}

int	all_eat(t_data *data)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < data->number_philos)
	{
		if (data->philos[i].eat_nb >= data->time2eat)
			counter++;
		i++;
	}
	if (counter == data->number_philos)
		return (1);
	return (0);
}
