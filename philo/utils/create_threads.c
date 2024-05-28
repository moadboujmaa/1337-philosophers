/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:11:12 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/27 16:20:52 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	*routine(void *param)
{
	t_philo	*philo;

	philo = (t_philo *) param;
	if (philo->id % 2 == 0)
		thinking(philo->data, philo->id);
	while (1)
	{
		if (eating(philo->data, philo->id))
			break ;
		if (sleeping(philo->data, philo->id))
			break ;
		if (thinking(philo->data, philo->id))
			break ;
	}
	return (0);
}

void	create_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_philos)
		pthread_create(&data->philos[i].thread, NULL,
			&routine, &(data)->philos[i]);
	i = -1;
	while (++i < data->number_philos)
		pthread_join(data->philos[i].thread, NULL);
}
