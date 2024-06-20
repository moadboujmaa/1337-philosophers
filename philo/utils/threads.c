/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:11:12 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/20 11:36:29 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *) param;
	if (philo->id % 2 == 0)
		sleeping(philo->data, philo->id);
	while (!stop_method(philo->data, 'g', 0))
	{
		thinking(philo->data, philo->id);
		eating(philo->data, philo->id);
		sleeping(philo->data, philo->id);
	}
	return (0);
}

static int	watcher(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_philos)
	{
		if (data->should_count && all_eat(data))
		{
			stop_method(data, 's', 1);
			break ;
		}
		if (check_death(data, i) && !stop_method(data, 'g', 0))
		{
			stop_method(data, 's', 1);
			died(data, i + 1);
			break ;
		}
		usleep(300);
		i++;
		if (i == data->number_philos)
			i = 0;
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
