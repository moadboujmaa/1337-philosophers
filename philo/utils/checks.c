/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:58:37 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/28 13:03:39 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_death(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_philos)
	{
		if (current_time() - data->philos[i].last_time_eat >= data->time2die)
			return (1);
	}
	return (0);
}
