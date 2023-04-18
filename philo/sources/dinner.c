/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:35:22 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/18 20:10:54 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->forks[1]);
	print_actions(philo, FORK1);	
	pthread_mutex_lock(philo->forks[0]);
	print_actions(philo, FORK2);
}

long get_last_meal(t_philo *philo)
{
	long last_meal;

	pthread_mutex_lock(&(philo->data->mutex_last_meal));
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&(philo->data->mutex_last_meal));
	return (last_meal);
}

is_dinner_over(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_stop));
	if (philo->data->flag)
	{
		
	}
	pthread_mutex_lock(&(philo->data->mutex_stop));
}

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
	
	while (!is_dinner_over(t_philo *philo))
	{
		take_fork(philo);
		pthread_mutex_lock(&(philo->data->mutex_eat));
		philo->meals_done++;	
		usleep(philo->time_eat * 1000);
		print_actions(philo, EAT);
		philo->last_meal = get_time_in_ms();
		pthread_mutex_unlock(&(philo->data->mutex_eat));
		pthread_mutex_unlock(philo->forks[1]);
		pthread_mutex_unlock(philo->forks[0]);
		print_actions(philo, SLEEP);
		usleep(philo->time_sleep * 1000);
		print_actions(philo, THINK);	
	}
	return (NULL);
}
