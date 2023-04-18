/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:59:44 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/18 19:18:14 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int have_meals(t_philo *philo)
{
	int i;
	i = -1;
	(void)philo;
		// while (++i < philo->data->tot)
	// {
	// 	if (philo->meals_done == philo->meals)
	// 		return(1);
	// }
	return(0);
}

void dinner_end(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_flag));
	philo->data->flag = 1;
	pthread_mutex_unlock(&(philo->data->mutex_flag));
}

void *check_death(void *arg)
{
	t_philo *philo;
	int i;
	long time;
	i = -1;	
	philo = (t_philo*)arg;
	while (1)
	{
		usleep(1000);
		i = -1;	
		if(have_meals(philo) == 1)
			break;
		while (++i < philo->data->tot)
		{
			pthread_mutex_lock(&(philo->data->mutex_monitor));
			time = get_time_in_ms() - get_last_meal(&philo[i]);
			if (time > philo->time_die)
			{		
				pthread_mutex_unlock(&(philo->data->mutex_monitor));
				dinner_end(philo);
				print_actions(philo, DEAD);
				return (NULL);
			}
			pthread_mutex_unlock(&(philo->data->mutex_monitor));
		}
	}
	return (NULL);
}