/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:53:21 by mgordag           #+#    #+#             */
/*   Updated: 2022/10/15 18:49:21 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_routine(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->philos_count)
	{
		pthread_join(philos[i].philosopher, NULL);
	}
	i = -1;
	while (++i < data->philos_count)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->write_mutex));
	pthread_mutex_destroy(&(data->dead_check));
	pthread_mutex_destroy(&(data->meal_check));
}

void	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	print_msg(data, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&data->forks[philo->right_fork]);
	print_msg(data, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&data->meal_check);
	print_msg(data, philo->philo_id, "is eating");
	philo->time_spent = get_time();
	pthread_mutex_unlock(&data->meal_check);
	ft_usleep(data->time_to_eat, data);
	philo->meal_count++;
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
}

void	*routine(void *args)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)args;
	data = philo->data;
	if (philo->philo_id % 2)
		usleep(1000);
	while (!is_someone_dead(data))
	{
		eating(philo);
		print_msg(data, philo->philo_id, "is sleeping");
		ft_usleep(data->time_to_sleep, data);
		print_msg(data, philo->philo_id, "is thinking");
		if (philo->meal_count == data->repetition)
			break ;
	}
	return (NULL);
}

void	is_dead(t_data *data, t_philo *philos)
{
	int	i;

	while (!(data->all_ate))
	{
		i = -1;
		while (++i < data->philos_count && !is_someone_dead(data))
		{
			pthread_mutex_lock(&(data->meal_check));
			if (time_diff(philos[i].time_spent, get_time()) > data->lifespan)
			{
				print_msg(data, i, "is dead");
				change_value(data, &data->someone_dead);
			}
			pthread_mutex_unlock(&(data->meal_check));
			usleep(100);
		}
		if (is_someone_dead(data))
			break ;
		pthread_mutex_lock(&data->dead_check);
		i = control_exit_status(data, philos);
		pthread_mutex_unlock(&data->dead_check);
		if (i == data->philos_count)
			change_value(data, &data->all_ate);
	}
}

int	start_process(t_data *data)
{
	t_philo	*phi;
	int		i;

	i = -1;
	phi = data->philo_data;
	data->first_time = get_time();
	while (++i < data->philos_count)
	{
		phi[i].time_spent = get_time();
		if (pthread_create(&phi[i].philosopher, NULL, routine, &phi[i]))
			return (1);
	}
	is_dead(data, data->philo_data);
	exit_routine(data, data->philo_data);
	return (0);
}
