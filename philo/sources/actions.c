/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:58:23 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/24 17:04:05 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
