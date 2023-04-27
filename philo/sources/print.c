/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:55:25 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/27 17:52:36 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_actions(t_philo *philo, int flag)
{
	if (is_dinner_over(philo) == 0 && are_philos_full(philo) == 0)
	{
		pthread_mutex_lock(&(philo->data->mutex_print));
		if (flag == EAT)
			printf("%ld Philosofer %d is eating!\n",
				(get_time_in_ms() - philo->data->start_time), philo->id);
		else if (flag == THINK)
			printf("%ld Philosofer %d is thinking!\n",
				(get_time_in_ms() - philo->data->start_time), philo->id);
		else if (flag == SLEEP)
			printf("%ld Philosofer %d is sleeping!\n",
				(get_time_in_ms() - philo->data->start_time), philo->id);
		else if (flag == FORK)
			printf("%ld Philosofer %d has taken a fork.\n",
				(get_time_in_ms() - philo->data->start_time), philo->id);
		else if (flag == DEAD)
			printf("%ld Philosofer %d died.\n",
				(get_time_in_ms() - philo->data->start_time), philo->id);
		pthread_mutex_unlock(&(philo->data->mutex_print));
	}
}
