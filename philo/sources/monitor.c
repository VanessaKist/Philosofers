/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:59:44 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/24 17:06:23 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void dinner_end(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_flag));
	philo->data->flag = 1;
	pthread_mutex_unlock(&(philo->data->mutex_flag));
}

static int	get_meals_done(t_philo *philo)
{
	int	meals_done;

	pthread_mutex_lock(&philo->data->mutex_stop);
	meals_done = philo->meals_done;
	pthread_mutex_unlock(&philo->data->mutex_stop);
	return (meals_done);
}

static long get_last_meal(t_philo *philo)
{
	long last_meal;

	pthread_mutex_lock(&(philo->data->mutex_last_meal));
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&(philo->data->mutex_last_meal));
	return (last_meal);
}

int	have_meals(t_philo *philo)
{
	int	i;
	int	cont;

	cont = 0;
	i = 0;
	while (i < philo->data->tot)
	{
		if (get_meals_done(&philo[i]) == philo->meals)
			cont++;
		i++;
	}
	if (cont == philo->data->tot)
	{
		pthread_mutex_lock(&(philo->data->mutex_flag));
		philo->data->flag2 = 1;
		pthread_mutex_unlock(&(philo->data->mutex_flag));
		return (1);
	}
	return (0);
}

void *check_death(void *arg)
{
	t_philo *philo;
	int i;
	long time;
	i = -1;	
	philo = (t_philo*)arg;
	while (!have_meals(philo))
	{
		usleep(1000);
		i = -1;	
		while (++i < philo->data->tot)
		{	
			pthread_mutex_lock(&(philo->data->mutex_monitor));
			time = get_time_in_ms() - get_last_meal(&philo[i]);
			if (time > philo[i].time_die)
			{		
				print_actions(&philo[i], DEAD);
				dinner_end(&philo[i]);
				pthread_mutex_unlock(&(philo->data->mutex_monitor));
				return (NULL);
			}
			pthread_mutex_unlock(&(philo->data->mutex_monitor));
		}
	}
	return (NULL);
}