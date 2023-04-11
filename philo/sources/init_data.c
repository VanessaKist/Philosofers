/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:48:20 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/11 18:56:36 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//STATIC

t_data *new_data(char **argv)
{
    t_data *data;
    
    data = malloc(sizeof(t_data));
    data->tot = atoi(argv[1]);
    data->last_meal = get_time_in_ms();
    data->time_spended = data->last_meal;
    data->death = data->last_meal + atoi(argv[4]);
 //   data->fork = init_forks(data); //alocation of memory for forks
    return(data);
}

// t_fork	**init_forks(t_data *data)
// {
// 	int	i;
// 	t_fork	**forks;

// 	forks = malloc(sizeof(t_fork **) * data->tot);
// 	i = 0;
// 	while (i < data->tot)
// 	{
// 		forks[i] = malloc(sizeof(t_fork));
// 		//pthread_mutex_init(forks[i], NULL);
// 		i++;
// 	}
// 	return (forks);
// }

// void	free_forks(t_data *data)
// {
// 	int	index;

// 	index = 0;
// 	while (index < data->tot)
// 	{
// 		pthread_mutex_destroy(data->forks[index]);
// 		index++;
// 	}
// 	free(data->forks);
// }

t_philo	*new_philo(t_data *data, char **argv, int i)
{
	t_philo	*philo;
    
    philo = malloc(sizeof(t_philo));
    philo->time_eat = atoi(argv[2]);
    philo->time_sleep = atoi(argv[3]);
    philo->time_die = atoi(argv[4]);
    philo->id = i + 1;
	philo->condition = THINKING;
	philo->fork_r = NULL;
    philo->fork_l = NULL;
    philo->data = data;
	return (philo);
}
//https://pages.mtu.edu/~shene/NSF-3/e-Book/MONITOR/Philosopher/MON-example-Philos.html