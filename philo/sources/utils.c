/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:54:48 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/18 17:57:58 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_actions(t_philo *philo, int flag)
{
	pthread_mutex_lock(&(philo->data->mutex_print));
	if (flag == EAT)
		printf("%ld Philosofer %d is eating!\n", 
			(get_time_in_ms() - get_last_meal(philo)), philo->id);
	else if (flag == THINK)
		printf("%ld Philosofer %d is thinking!\n", 
			(get_time_in_ms() - philo->data->start_time), philo->id);
	else if (flag == SLEEP)
		printf("%ld Philosofer %d is sleeping!\n", 
			(get_time_in_ms() - philo->data->start_time), philo->id);
	else if (flag == FORK1)
		printf("%ld Philosofer %d has taken a fork.\n", 
			(get_time_in_ms() - philo->data->start_time), philo->id);
	else if	(flag == FORK2)
		printf("%ld Philosofer %d has taken a fork.\n", 
			(get_time_in_ms() - philo->data->start_time), philo->id);
	else if (flag == DEAD)
		printf("%ld Philosofer %d has died.\n", 
			(get_time_in_ms() - philo->data->start_time), philo->id);
	pthread_mutex_unlock(&(philo->data->mutex_print));
}
