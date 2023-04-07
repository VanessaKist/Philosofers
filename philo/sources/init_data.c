/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:48:20 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/07 21:44:19 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

//STATIC

t_data *new_data(char **argv)
{
    t_data *data;
    
    data = malloc(sizeof(t_data));
    data->last_meal = get_time_in_ms();
    data->time_spended = data->last_meal;
    data->death = data->last_meal + atoi(argv[4]);
	data->forks = init_forks(atoi(argv[1]); //alocation of memory for forks
    return(data);
}

t_fork	*init_forks(int tot)
{
	t_fork	*forks;
	int		i;

	i = 0;
	forks = malloc(tot * sizeof(t_fork));
	while (i < tot)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	*new_philo(t_data *data, char **argv, int i)
{
	t_philo	*philo;
    
    philo = malloc(sizeof(t_philo));
    philo->time_eat = atoi(argv[2]);
    philo->time_sleep = atoi(argv[3]);
    philo->time_die = atoi(argv[4]);
    philo->id = i + 1;
	philo->condition = THINKING;
	philo->left_fork = &forks[i];
	philo->right_fork = &forks[(i + 1) % ft_atoi(argv[1])]; // to prevent more fork than philos
    philo->data = data;
	return (philo);
}
