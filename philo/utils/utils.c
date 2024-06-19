/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:35:47 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/19 12:21:18 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(data->print, NULL);
	pthread_mutex_init(&(data->dead), NULL);
	while (i < data->number_philos)
	{
		pthread_mutex_init(data->philos[i].r_fork, NULL);
		i++;
	}
}

void	clear_program(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(data->print);
	free(data->print);
	while (i < data->number_philos)
	{
		pthread_mutex_destroy(data->philos[i].r_fork);
		pthread_mutex_destroy(&(data->philos[i].last_eat_mutex));
		free(data->philos[i].r_fork);
		i++;
	}
}

int	dead_method(t_data *data, char a, int new_val)
{
	int tmp;

	pthread_mutex_lock(&data->dead);
	if (a == 's')
		data->is_dead = new_val;
	tmp = data->is_dead;
	pthread_mutex_unlock(&data->dead);
	return (tmp);
}

int	ft_atoi(const char *str)
{
	unsigned long long int	res;
	int						sign;
	int						i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
