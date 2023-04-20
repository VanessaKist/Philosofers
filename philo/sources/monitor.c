/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:59:44 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/19 19:40:33 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int have_meals(t_philo *philo)
// {
// 	int i;
// 	i = -1;
// 	while (++i < philo->data->tot)
// 	{
// 		if (philo[i].meals_done == philo[i].meals)
// 			return(1);
// 	}
// 	return(0);
// }

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
		// if(have_meals(philo) == 1)
		// 	break;
		while (++i < philo->data->tot)
		{	
			pthread_mutex_lock(&(philo->data->mutex_monitor));
			time = get_time_in_ms() - get_last_meal(&philo[i]);
			if (time > philo->time_die)
			{		
				pthread_mutex_unlock(&(philo->data->mutex_monitor));
				print_actions(philo, DEAD);
				dinner_end(philo);
				return (NULL);
			}
			pthread_mutex_unlock(&(philo->data->mutex_monitor));
		}
	}
	return (NULL);
}