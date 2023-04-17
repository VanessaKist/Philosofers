/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:59:44 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/15 23:10:19 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *check_death(void *arg)
{
	t_philo *philo;
	int i;
	
	i = -1;	
	philo = (t_philo*)arg;
	while (++i < philo->data->tot)
	{
		//pthread_mutex_lock(&(philo->data->mutex));
		if ((get_time_in_ms() - philo[i].data->last_meal) >= philo[i].time_die)
		{		
		//	pthread_mutex_unlock(&(philo->data->mutex));
			printf("Dead.\n");
			return (NULL);
		}
	//	pthread_mutex_unlock(&(philo->data->mutex));
	}
}