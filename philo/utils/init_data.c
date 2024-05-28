/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:45:07 by mboujama          #+#    #+#             */
/*   Updated: 2024/05/27 15:38:47 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_data(t_data *dt, char **argv, int argc)
{
	ft_bzero(dt, sizeof(t_data));
	if (argc != 5 && argc != 6)
		return (0);
	dt->number_philos = ft_atoi(argv[1]);
	dt->time2die = ft_atoi(argv[2]);
	dt->time2eat = ft_atoi(argv[3]);
	dt->time2sleep = ft_atoi(argv[4]);
	if (argc == 6)
		dt->eat_nb = ft_atoi(argv[5]);
	if (dt->number_philos < 1 || dt->number_philos > 200 || dt->time2die < 60
		|| dt->time2eat < 60 || dt->time2sleep < 60)
		return (0);
	if (argc == 6 && dt->eat_nb <= 0)
		return (0);
	return (1);
}
