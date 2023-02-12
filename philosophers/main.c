/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:53:14 by mgordag           #+#    #+#             */
/*   Updated: 2022/10/15 17:20:00 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(data->philos_count * sizeof(pthread_mutex_t));
	while (++i < data->philos_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
	}
	if (pthread_mutex_init(&data->write_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&data->meal_check, NULL))
		return (1);
	if (pthread_mutex_init(&data->dead_check, NULL))
		return (1);
	return (0);
}

void	init_philosophers(t_data *data)
{
	int	i;

	i = -1;
	data->philo_data = malloc(data->philos_count * sizeof(t_philo));
	while (++i < data->philos_count)
	{
		data->philo_data[i].philo_id = i;
		data->philo_data[i].meal_count = 0;
		data->philo_data[i].left_fork = i;
		data->philo_data[i].right_fork = (i + 1) % data->philos_count;
		data->philo_data[i].time_spent = 0;
		data->philo_data[i].data = data;
	}
}

int	assign_values(t_data *data, char **av)
{
	data->philos_count = ft_atoi(av[1]);
	data->lifespan = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->all_ate = 0;
	data->someone_dead = 0;
	if (data->philos_count < 1 || data->lifespan < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0)
		return (1);
	if (av[5])
	{
		data->repetition = ft_atoi(av[5]);
		if (data->repetition <= 0)
			return (1);
	}
	else
		data->repetition = -1;
	if (init_mutex(data))
		return (1);
	init_philosophers(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (ft_putstr_fd(2, "Invalid argument size"));
	if (assign_values(&data, av))
		return (ft_putstr_fd(2, "Error on assigning initial values"));
	if (data.philos_count == 1)
		process_w_one(&data);
	else
	{
		if (start_process(&data))
			return (ft_putstr_fd(2, "Error on process"));
	}
	free(data.forks);
	free(data.philo_data);
	return (0);
}
