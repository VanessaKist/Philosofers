/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:35:22 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/17 18:17:29 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	take_fork(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->forks[1]);
// 	printf("%ld Philosofer %d has taken a fork.\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
// 	pthread_mutex_lock(philo->forks[0]);
// 	printf("%ld Philosofer %d has taken a fork.\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
// }

// int get_last_meal(t_philo *philo)
// {
// 	int last_meal;

// 	pthread_mutex_lock(&(philo->data->mutex_last_meal));
// 	last_meal = philo->data->last_meal;
// 	pthread_mutex_unlock(&(philo->data->mutex_last_meal));
// 	return (last_meal);
// }

// void print_actions(t_philo *philo, int flag)
// {
// 	pthread_mutex_lock(&(philo->data->mutex_print));
// 	if (flag == EAT)
// 		printf("%ld Philosofer %d is eating!\n", (get_time_in_ms() - get_last_meal(philo)), philo->id);
// 	else if (flag == THINK)
// 		printf("%ld Philosofer %d is thinking!\n", (get_time_in_ms() - get_last_meal(philo)), philo->id);
// 	else
// 		printf("%ld Philosofer %d is sleeping!\n", (get_time_in_ms() - get_last_meal(philo)), philo->id);
// 	pthread_mutex_unlock(&(philo->data->mutex_print));
// }

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
	
	printf("hello\n");
	//take_fork(philo);
	// pthread_mutex_lock(&(philo->data->mutex_eat));
	// philo->meals_done++;
	// philo->data->last_meal = get_time_in_ms();
	// print_actions(philo, EAT);
	// pthread_mutex_unlock(&(philo->data->mutex_eat));
    // usleep(philo->time_eat * 1000);
	// //pthread_mutex_unlock(philo->forks[1]);
	// //pthread_mutex_unlock(philo->forks[0]);
	// print_actions(philo, SLEEP);
	// usleep(philo->time_sleep * 1000);
	// print_actions(philo, THINK);
	 return (NULL);
}
