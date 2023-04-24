/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:48:20 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/24 15:32:11 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//STATIC

t_data *new_data(char **argv)
{
    t_data *data;
    
    data = malloc(sizeof(t_data));
    data->tot = atoi(argv[1]);
 	data->start_time = get_time_in_ms();
    data->forks = init_forks(data);
	data->flag = 0;
	data->flag2 = 0;
	pthread_mutex_init(&data->mutex_last_meal, NULL);
	pthread_mutex_init(&data->mutex_eat, NULL);
	pthread_mutex_init(&data->mutex_stop, NULL);
	pthread_mutex_init(&data->mutex_meals, NULL);
	pthread_mutex_init(&data->mutex_print, NULL);
	pthread_mutex_init(&data->mutex_monitor, NULL);
    return(data);
}

 t_fork	*init_forks(t_data *data)
 {
 	int	i;
 	t_fork	*forks;

 	forks = malloc(sizeof(t_fork) * data->tot);
 	i = 0;
 	while (i < data->tot)
 	{
 		pthread_mutex_init(&forks[i], NULL);
 		i++;
 	}
	return (forks);
}

t_philo	*new_philo(t_data *data, char **argv, int argc, int i)
{
    t_philo *philo;
	long	last_meal;

	last_meal = get_time_in_ms();
	philo = malloc(atoi(argv[1]) * sizeof(t_philo));
	while (i < atoi(argv[1]))
	{   
		philo[i].time_eat = atoi(argv[2]);
		philo[i].time_sleep = atoi(argv[3]);
		philo[i].time_die = atoi(argv[4]);
		philo[i].meals_done = 0;
		philo[i].id = i + 1;
		philo[i].last_meal = last_meal;
		if (argc == 6)
			philo[i].meals = atoi(argv[5]);
		philo[i].start = 0;
		philo[i].fork_right = &data->forks[i];
		if (i == 0)
			philo[i].fork_left = &data->forks[data->tot - 1];
		else
			philo[i].fork_left = &data->forks[i - 1];
		philo[i].data = data;
		i++;
	}
	return(philo);
}
