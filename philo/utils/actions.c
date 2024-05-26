/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:37:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/26 15:47:32 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eating(t_data *data, int philo_id)
{
	long	time;

	time = data->program_start - current_time();
	printf("{%ld} %d is eating\n", philo_id);
	ft_usleep(data->time2eat);
	return (0);
}

int	thinking(t_data *data, int philo_id)
{
	long	time;

	time = data->program_start - current_time();
	printf("{%ld} %d is thinking\n", philo_id);
	// ft_usleep(data->time2);
	return (0);
}

int	sleeping(t_data *data, int philo_id)
{
	long	time;

	time = data->program_start - current_time();
	printf("{%ld} %d is sleeping\n", philo_id);
	ft_usleep(data->time2sleep);
	return (0);
}

int	died(t_data *data, int philo_id)
{
	printf("{%ld} %d is died\n", philo_id);
	return (0);
}
