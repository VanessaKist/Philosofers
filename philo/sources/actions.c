/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:58:23 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/25 17:29:55 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_philo *philo)
{
	if (is_dinner_over(philo) == 0 && are_philos_full(philo) == 0)
		msleep(philo->time_eat);
	else
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (is_dinner_over(philo) == 0 && are_philos_full(philo) == 0)
		msleep(philo->time_sleep);
	else
		return (1);
	return (0);
}
