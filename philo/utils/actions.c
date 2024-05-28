/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:37:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/28 10:26:13 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eating(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	data->philos[philo_id].last_time_eat = current_time();
	printf("%lld %d is eating\n", time, philo_id);
	ft_usleep(data->time2eat);
	return (0);
}

int	thinking(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	printf("%lld %d is thinking\n", time, philo_id);
	return (0);
}

int	sleeping(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	printf("%lld %d is sleeping\n", time, philo_id);
	ft_usleep(data->time2sleep);
	return (0);
}

int	died(t_data *data, int philo_id)
{
	long long	time;

	time = current_time() - data->program_start;
	printf("%lld %d is died\n", time, philo_id);
	return (0);
}
