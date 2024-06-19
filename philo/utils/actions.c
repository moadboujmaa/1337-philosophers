/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:37:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/16 13:17:22 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eating(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	if (!data->is_dead)
	{
		data->philos[philo_id - 1].last_time_eat = current_time();
		pthread_mutex_lock(data->philos[philo_id - 1].r_fork);
		pthread_mutex_lock(data->print);
		printf("%lld %d has taken a fork\n", time, philo_id);
		pthread_mutex_unlock(data->print);
		pthread_mutex_lock(data->philos[philo_id - 1].l_fork);
		pthread_mutex_lock(data->print);
		printf("%lld %d has taken a fork\n", time, philo_id);
		printf("%lld %d is eating\n", time, philo_id);
		pthread_mutex_unlock(data->print);
		ft_sleep(data->time2eat);
		pthread_mutex_unlock(data->philos[philo_id - 1].r_fork);
		pthread_mutex_unlock(data->philos[philo_id - 1].l_fork);
		data->philos[philo_id - 1].eat_nb++;
	}
	return (0);
}

int	thinking(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	if (!data->is_dead)
	{
		pthread_mutex_lock(data->print);
		printf("%lld %d is thinking\n", time, philo_id);
		pthread_mutex_unlock(data->print);
	}
	return (0);
}

int	sleeping(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	if (!data->is_dead)
	{
		pthread_mutex_lock(data->print);
		printf("%lld %d is sleeping\n", time, philo_id);
		pthread_mutex_unlock(data->print);
		ft_sleep(data->time2sleep);
	}
	return (0);
}

int	died(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	if (!data->is_dead)
	{
		pthread_mutex_lock(data->print);
		printf("%lld %d is died\n", time, philo_id);
		pthread_mutex_unlock(data->print);
	}
	return (0);
}
