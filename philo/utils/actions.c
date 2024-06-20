/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:37:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/20 11:45:33 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_print_action(int philo_id, char *msg, t_data *data)
{
	pthread_mutex_lock(data->print);
	if (!stop_method(data, 'g', 0))
		printf("%lld %d %s\n", current_time() - data->program_start,
			philo_id, msg);
	pthread_mutex_unlock(data->print);
}

int	eating(t_data *data, int philo_id)
{
	if (!stop_method(data, 'g', 0))
	{
		pthread_mutex_lock(data->philos[philo_id - 1].r_fork);
		ft_print_action(philo_id, "has taken a fork", data);
		pthread_mutex_lock(data->philos[philo_id - 1].l_fork);
		pthread_mutex_lock(&(data->philos[philo_id - 1].last_eat_mutex));
		if (current_time() - data->philos[philo_id - 1].last_time_eat
			<= data->time2die)
			data->philos[philo_id - 1].last_time_eat = current_time();
		pthread_mutex_unlock(&(data->philos[philo_id - 1].last_eat_mutex));
		ft_print_action(philo_id, "has taken a fork", data);
		ft_print_action(philo_id, "is eating", data);
		ft_sleep(data->time2eat, data);
		pthread_mutex_unlock(data->philos[philo_id - 1].r_fork);
		pthread_mutex_unlock(data->philos[philo_id - 1].l_fork);
		data->philos[philo_id - 1].eat_nb++;
	}
	return (0);
}

int	thinking(t_data *data, int philo_id)
{
	if (!stop_method(data, 'g', 0))
		ft_print_action(philo_id, "is thinking", data);
	return (0);
}

int	sleeping(t_data *data, int philo_id)
{
	if (!stop_method(data, 'g', 0))
	{
		ft_print_action(philo_id, "is sleeping", data);
		ft_sleep(data->time2sleep, data);
	}
	return (0);
}

int	died(t_data *data, int philo_id)
{
	pthread_mutex_lock(data->print);
	printf("%lld %d died\n", current_time() - data->program_start, philo_id);
	pthread_mutex_unlock(data->print);
	return (0);
}
