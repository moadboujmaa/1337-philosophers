/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:11:12 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/10 12:57:10 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *) param;
	if (philo->id % 2 == 0)
	{
		thinking(philo->data, philo->id);
		usleep(50);
	}
	while (!philo->data->is_dead)
	{
		eating(philo->data, philo->id);
		sleeping(philo->data, philo->id);
		thinking(philo->data, philo->id);
	}
	return (0);
}

static int	watcher(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < data->number_philos)
		{
			if (check_death(data) && !data->is_dead)
			{
				usleep(100);
				died(data, i);
				data->is_dead = 1;
				return (1);
			}
			i++;
			if (i == data->number_philos)
				i = 0;
		}
	}
	return (0);
}

void	save_time(t_data *data)
{
	int	i;

	i = 0;
	data->program_start = current_time();
	while (i < data->number_philos)
	{
		data->philos[i].last_time_eat = data->program_start;
		i++;
	}
}

void	create_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_philos)
		pthread_create(&data->philos[i].thread, NULL,
			&routine, &(data)->philos[i]);
	i = -1;
	watcher(data);
	while (++i < data->number_philos)
		pthread_join(data->philos[i].thread, NULL);
}
