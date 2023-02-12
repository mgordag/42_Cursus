/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:53:18 by mgordag           #+#    #+#             */
/*   Updated: 2022/10/15 18:49:31 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	long long int	time_spent;
	int				meal_count;
	int				philo_id;
	int				left_fork;
	int				right_fork;
	pthread_t		philosopher;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	long long int	first_time;
	int				someone_dead;
	int				last_time;
	int				time_to_eat;
	int				time_to_sleep;
	int				lifespan;
	int				repetition;
	int				all_ate;
	int				philos_count;
	pthread_mutex_t	dead_check;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	*forks;
	t_philo			*philo_data;
}	t_data;

int				is_someone_dead(t_data *data);
int				ft_atoi(char *str);
int				ft_putstr_fd(int fd, char *str);
int				start_process(t_data *data);
int				control_exit_status(t_data *data, t_philo *philos);
int				process_w_one(t_data *data);
void			exit_routine(t_data *data, t_philo *philos);
void			print_msg(t_data *data, int id, char *str);
void			ft_usleep(int ms, t_data *data);
void			free_all(t_data *data);
void			change_value(t_data *data, int *value);
void			is_dead(t_data *data, t_philo *philos);
long long int	get_time(void);
long long int	time_diff(long long int past, long long int now);

#endif