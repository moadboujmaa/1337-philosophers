/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:37:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/08 12:24:49 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eating(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	data->philos[philo_id].last_time_eat = current_time();
	pthread_mutex_lock(data->philos[philo_id].r_fork);
	pthread_mutex_lock(data->print);
	printf("%lld %d taking the right fork\n", time, philo_id);
	pthread_mutex_unlock(data->print);
	pthread_mutex_lock(data->philos[philo_id].l_fork);
	pthread_mutex_lock(data->print);
	printf("%lld %d taking the left fork\n", time, philo_id);
	printf("%lld %d is eating\n", time, philo_id);
	pthread_mutex_unlock(data->print);
	ft_usleep(data->time2eat);
	pthread_mutex_unlock(data->philos[philo_id].r_fork);
	pthread_mutex_unlock(data->philos[philo_id].l_fork);
	return (0);
}

int	thinking(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	pthread_mutex_lock(data->print);
	printf("%lld %d is thinking\n", time, philo_id);
	pthread_mutex_unlock(data->print);
	return (0);
}

int	sleeping(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	pthread_mutex_lock(data->print);
	printf("%lld %d is sleeping\n", time, philo_id);
	ft_usleep(data->time2sleep);
	pthread_mutex_unlock(data->print);
	ft_usleep(data->time2sleep);
	return (0);
}

int	died(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	pthread_mutex_lock(data->print);
	printf("%lld %d is died\n", time, philo_id);
	pthread_mutex_unlock(data->print);
	return (0);
}
