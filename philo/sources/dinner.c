/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:35:22 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/24 16:19:21 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_actions(philo, FORK1);	
	pthread_mutex_lock(philo->fork_right);
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

void increase_meals(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_meals));
	philo->meals_done++;
	pthread_mutex_unlock(&(philo->data->mutex_meals));
}

int is_dinner_over(t_philo *philo)
{
	if (philo->data->flag == 1)
		return (1);
	return (0);
}

int are_philos_full(t_philo *philo)
{
	if (philo->data->flag2 == 1)
		return (1);
	return (0);
}

int eating(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->time_eat)
	{
		if (is_dinner_over(philo) == 0)	
			usleep(1000);
		else
		{
			pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(philo->fork_right);		
			return (1);
		}
		i++;
	}
	return (0);
}

int sleeping(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->time_sleep)
	{
		if (is_dinner_over(philo) == 0 && are_philos_full(philo) == 0)
			usleep(1000);
		else
			return (1);
		i++;	
	}
	return (0);
}

void *philo_solo(t_philo *philo)
{
	print_actions(philo, THINK);
	pthread_mutex_lock(philo->fork_left);
	print_actions(philo, FORK1);
	pthread_mutex_unlock(philo->fork_left);
	return (NULL);
}

void *routine(void * arg)
{
    t_philo *philo;
	
    philo = (t_philo*)arg;
	
	if (philo->data->tot == 1)
		return (philo_solo(philo));
	if (philo->start == 0 && philo->id % 2 == 0)
	{
		philo->start = 1;
		usleep(1000 * 35);
	}
	while(is_dinner_over(philo) == 0 && are_philos_full(philo) == 0)
	{
		print_actions(philo, THINK);
		take_fork(philo);
		increase_meals(philo);
		print_actions(philo, EAT);
		philo->last_meal = get_time_in_ms();
		if (eating(philo) == 1)
			break;
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		print_actions(philo, SLEEP);
		sleeping(philo);
	}
	return (NULL);
}
