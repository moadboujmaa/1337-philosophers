/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:29:43 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/27 09:15:28 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	current_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000L + tv.tv_usec / 1000;
	return (time);
}

static long long	current_time_mic(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000000LL + tv.tv_usec;
	return (time);
}

void	ft_usleep(int msec)
{
	long long	cur_time;
	long long	time2wait;

	cur_time = current_time_mic();
	time2wait = cur_time + msec;
	while (cur_time < time2wait)
		cur_time = current_time_mic();
}
