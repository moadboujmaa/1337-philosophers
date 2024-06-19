/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:05:19 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/19 10:59:07 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	long long		last_time_eat;
	int				eat_nb;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				number_philos;
	int				time2die;
	int				is_dead;
	int				time2eat;
	int				time2sleep;
	int				eat_nb;
	int				dead_id;
	long long		program_start;
	pthread_mutex_t	*print;
	t_philo			philos[200];
}	t_data;

// Actions
int			eating(t_data *data, int philo_id);
int			thinking(t_data *data, int philo_id);
int			sleeping(t_data *data, int philo_id);
int			died(t_data *data, int philo_id);

int			init_data(t_data *data, char **argv, int argc);
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
int			add_philos(t_data *data);
int			check_death(t_data *data);
void		ft_sleep(int msec);
long long	current_time(void);
void		create_threads(t_data *data);
void		clear_program(t_data *data);
void		init_mutexes(t_data *data);

#endif