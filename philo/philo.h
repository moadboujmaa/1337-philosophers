/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:05:19 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/21 12:55:11 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int			id;
	int			last_meal;
	pthread_t	thread;
}	t_philo;

typedef struct s_data
{
	int		number_philos;
	int		time2die;
	int		time2eat;
	int		time2sleep;
	int		eat_nb;
	t_philo	philos[200];
}	t_data;

int		init_data(t_data *data, char **argv, int argc);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

int		add_philos(t_data *data);

// Actions
int		eating(t_philo	philo);
int		thinking(t_philo	philo);
int		sleeping(t_philo	philo);

void	ft_usleep(int msec);

#endif