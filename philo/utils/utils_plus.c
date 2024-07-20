/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:29:37 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/20 14:37:02 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	stop_method(t_data *data, char a, int new_val)
{
	int	tmp;

	pthread_mutex_lock(&data->dead);
	if (a == 's')
		data->is_dead = new_val;
	tmp = data->is_dead;
	pthread_mutex_unlock(&data->dead);
	return (tmp);
}

int	nb_eat(t_philo *philo, char a)
{
	int	tmp;

	pthread_mutex_lock(&philo->nb_eat_mutex);
	if (a == 's')
		philo->eat_nb++;
	tmp = philo->eat_nb;
	pthread_mutex_unlock(&philo->nb_eat_mutex);
	return (tmp);
}
