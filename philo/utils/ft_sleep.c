/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:29:43 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/08 16:09:57 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	current_time(void)
{
	struct timeval	tv;
	size_t			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	ft_sleep(int msec, t_data *data)
{
	size_t	cur_time;
	size_t	time2wait;

	cur_time = current_time();
	time2wait = cur_time + msec;
	while (cur_time < time2wait)
	{
		cur_time = current_time();
		if (stop_method(data, 'g', 0))
			break ;
		usleep(200);
	}
}
