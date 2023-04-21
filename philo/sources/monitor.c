/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:59:44 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/20 20:53:00 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
		while (++i < philo->data->tot)
		{	
			pthread_mutex_lock(&(philo->data->mutex_monitor));
			time = get_time_in_ms() - get_last_meal(&philo[i]);
			if (time >= philo[i].time_die)
			{		
				print_actions(&philo[i], DEAD);
				dinner_end(&philo[i]);
				pthread_mutex_unlock(&(philo->data->mutex_monitor));
				return (NULL);
			}
			pthread_mutex_unlock(&(philo->data->mutex_monitor));
		}
	}
	return (NULL);
}