/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:59:44 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/20 16:56:31 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_sim_stop_flag(t_philo *philo, bool state)
{
	pthread_mutex_lock(&(philo->data->mutex_stop));
		philo->data->sim_stop = state;
		printf("SIM_STOP: %d\n", philo->data->sim_stop);
	pthread_mutex_lock(&(philo->data->mutex_stop));
}

void dinner_end(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_flag));
	philo->data->flag = 1;
	printf("FLAG: %d\n", philo->data->flag);
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
			if (time > philo[i].time_die)
			{		
				printf("FLAG: %d\n", philo->data->flag);
				print_actions(philo, DEAD);
				//set_sim_stop_flag(philo, true);
				dinner_end(philo);
				pthread_mutex_unlock(&(philo->data->mutex_monitor));
				return (NULL);
			}
			pthread_mutex_unlock(&(philo->data->mutex_monitor));
		}
	}
	return (NULL);
}