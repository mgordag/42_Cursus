/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_with_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:09:31 by mgordag           #+#    #+#             */
/*   Updated: 2022/10/15 18:49:05 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_one(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	print_msg(data, philo->philo_id, "has taken a fork");
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	ft_usleep(data->lifespan, data);
	print_msg(data, philo->philo_id, "is dead");
}

void	*routine_one(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	eating_one(philo);
	return (NULL);
}

int	process_w_one(t_data *data)
{
	t_philo	*phi;
	int		i;

	i = -1;
	phi = data->philo_data;
	data->first_time = get_time();
	while (++i < data->philos_count)
	{
		if (pthread_create(&phi[i].philosopher, NULL, routine_one, &phi[i]))
			return (1);
	}
	exit_routine(data, data->philo_data);
	return (0);
}

void	change_value(t_data *data, int *value)
{
	pthread_mutex_lock(&data->dead_check);
	*value = 1;
	pthread_mutex_unlock(&data->dead_check);
}

int	control_exit_status(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (data->repetition != -1 && i < data->philos_count
		&& philos[i].meal_count >= data->repetition)
		i++;
	return (i);
}
