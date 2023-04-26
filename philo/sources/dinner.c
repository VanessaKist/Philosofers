/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:35:22 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/26 17:22:40 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	increase_meals(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_meals));
	philo->meals_done++;
	pthread_mutex_unlock(&(philo->data->mutex_meals));
}

static void	*philo_solo(t_philo *philo)
{
	print_actions(philo, THINK);
	pthread_mutex_lock(philo->fork_left);
	print_actions(philo, FORK1);
	pthread_mutex_unlock(philo->fork_left);
	return (NULL);
}

static void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_last_meal);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->data->mutex_last_meal);
}

static void	unumbered_start(t_philo *philo)
{
	if (philo->start == 0 && philo->id % 2 == 0)
	{
		philo->start = 1;
		usleep(1000 * 35);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->tot == 1)
		return (philo_solo(philo));
	unumbered_start(philo);
	while (is_dinner_over(philo) == 0 && are_philos_full(philo) == 0)
	{
		print_actions(philo, THINK);
		usleep(500);
		take_fork(philo);
		print_actions(philo, EAT);
		increase_meals(philo);
		set_last_meal(philo);
		if (eating(philo) == 1)
			break ;
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		print_actions(philo, SLEEP);
		sleeping(philo);
	}
	return (NULL);
}
