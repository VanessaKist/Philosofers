/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:59:44 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/18 18:30:28 by vkist-si         ###   ########.fr       */
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
		if(have_meals(philo) == 1)
			break;
		i = -1;	
		while (++i < philo->data->tot)
		{
			//printf("Cheguei\n");
			pthread_mutex_lock(&(philo->data->mutex_monitor));
			time = get_time_in_ms() - get_last_meal(&philo[i]);
			if (time > philo->time_die)
			{		
				pthread_mutex_unlock(&(philo->data->mutex_monitor));
				print_actions(philo, DEAD);
				return (NULL);
			}
			pthread_mutex_unlock(&(philo->data->mutex_monitor));
		}
	}
	return (NULL);
}