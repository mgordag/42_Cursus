/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:53:27 by mgordag           #+#    #+#             */
/*   Updated: 2022/10/15 17:11:19 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int ms, t_data *data)
{
	long long	time;

	time = get_time();
	while (!is_someone_dead(data))
	{
		if (time_diff(time, get_time()) >= ms)
			break ;
		usleep(50);
	}
}

long long	time_diff(long long past, long long now)
{
	return (now - past);
}

void	print_msg(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->write_mutex));
	if (!is_someone_dead(data))
	{
		printf("%lld %i ", get_time() - data->first_time, id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(data->write_mutex));
	return ;
}

long long int	get_time(void)
{
	struct timeval	i;

	gettimeofday (&i, NULL);
	return ((i.tv_sec * 1000) + (i.tv_usec / 1000));
}

int	is_someone_dead(t_data *data)
{
	pthread_mutex_lock(&data->dead_check);
	if (data->someone_dead == 1)
	{
		pthread_mutex_unlock(&data->dead_check);
		return (1);
	}
	pthread_mutex_unlock(&data->dead_check);
	return (0);
}
