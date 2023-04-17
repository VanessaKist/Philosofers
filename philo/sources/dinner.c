/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:35:22 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/16 00:36:25 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->forks[1]);
	printf("%ld Philosofer %d has taken a fork.\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
	pthread_mutex_lock(philo->forks[0]);
	printf("%ld Philosofer %d has taken a fork.\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
}

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
	
	take_fork(philo);
	pthread_mutex_lock(&(philo->data->mutex_last_meal));
    printf("%ld Philosofer %d is eating!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
	pthread_mutex_unlock(&(philo->data->mutex_last_meal));
    usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(philo->forks[1]);
	pthread_mutex_unlock(philo->forks[0]);
	printf("%ld Philosofer %d is sleeping!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
	usleep(philo->time_sleep * 1000);
	printf("%ld Philosofer %d is thinking!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
}
