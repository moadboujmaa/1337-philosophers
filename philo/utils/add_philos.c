/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:02:53 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/26 14:35:54 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*routine(void *param)
{
	int	x;

	x = *(int *) param;
	return (0);
}

int	add_philos(t_data *data)
{
	t_philo	philo;
	int		i;

	i = -1;
	data->program_start = current_time();
	while (++i < data->number_philos)
	{
		philo.id = i;
		pthread_create(&philo.thread, NULL, &routine, &(philo.id));
		pthread_join(philo.thread, NULL);
	}
	return (1);
}
