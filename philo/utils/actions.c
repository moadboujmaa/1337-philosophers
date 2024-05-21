/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:37:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/21 12:51:54 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eating(t_philo philo)
{
	printf("{time} %d is eating\n", philo.id);
	// ft_usleep
	return (0);
}

int	thinking(t_philo philo)
{
	printf("{time} %d is thinking\n", philo.id);
	// ft_usleep
	return (0);
}

int	sleeping(t_philo philo)
{
	printf("{time} %d is sleeping\n", philo.id);
	// ft_usleep
	return (0);
}

int	died(t_philo philo)
{
	printf("{time} %d is died\n", philo.id);
	return (0);
}
