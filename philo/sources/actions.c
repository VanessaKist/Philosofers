/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:58:23 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/25 21:24:25 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_actions(philo, FORK1);
	pthread_mutex_lock(philo->fork_right);
	print_actions(philo, FORK2);
}

int is_dinner_over(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_flag));
	if (philo->data->flag == 1)
	{
		pthread_mutex_unlock(&(philo->data->mutex_flag));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->mutex_flag));
	return (0);
}

int are_philos_full(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_flag));
	if (philo->data->flag2 == 1)
	{
		pthread_mutex_unlock(&(philo->data->mutex_flag));
		return (1);
	}
	pthread_mutex_unlock(&(philo->data->mutex_flag));
	return (0);
}

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
