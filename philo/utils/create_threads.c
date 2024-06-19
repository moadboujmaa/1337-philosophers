/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:11:12 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/19 11:04:15 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *) param;
	if (philo->id % 2 == 0)
		sleeping(philo->data, philo->id);
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

	while (1)
	{
		i = 0;
		while (i < data->number_philos)
		{
			if (check_death(data) && !data->is_dead)
			{
				usleep(100);
				died(data, i + 1);
				data->is_dead = 1;
				return (1);
			}
			i++;
		}
	}
	return (0);
}

void	create_threads(t_data *data)
{
	int	i;

	init_mutexes(data);
	i = -1;
	while (++i < data->number_philos)
		pthread_create(&data->philos[i].thread, NULL,
			&routine, &(data)->philos[i]);
	i = -1;
	watcher(data);
	while (++i < data->number_philos)
		pthread_join(data->philos[i].thread, NULL);
}
