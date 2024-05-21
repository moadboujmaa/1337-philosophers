/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:29:43 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/21 12:58:11 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld, %d\n", tv.tv_sec, tv.tv_usec);
	return (0);
}

void	ft_usleep(int msec)
{
	(void) msec;
	current_time();
}
