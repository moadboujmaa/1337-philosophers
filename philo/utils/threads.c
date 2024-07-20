/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:11:12 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/20 11:55:53 by mboujama         ###   ########.fr       */
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
	return (NULL);
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
		i++;
		if (i == data->number_philos)
			i = 0;
	}
	return (0);
}

static void	*one_routine(void *param)
{
	t_data	*data;

	data = (t_data *) param;

	printf("%lld 1 has taken a fork\n", current_time() - data->program_start);
	ft_sleep(data->time2die, data);
	printf("%lld 1 died\n", current_time() - data->program_start);
	return (NULL);
}

static int	one_philo(t_data *data)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, &one_routine, data);
	pthread_join(thread, NULL);
	return (0);
}

void	create_threads(t_data *data)
{
	int	i;

	if (data->number_philos == 1)
	{
		one_philo(data);
		return ;
	}
	else
	{
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
}
