/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:12:09 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/12 23:45:17 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->forks[1]);
	printf("%ld Philosofer %d has taken a fork.\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
	pthread_mutex_lock(philo->forks[0]);
	printf("%ld Philosofer %d has taken a fork.\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
}

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
	
	if (philo->condition == THINKING)
	{
		take_fork(philo);
		pthread_mutex_lock(&(philo->data->mutex));
		philo->condition = EATING;
        printf("%ld Philosofer %d is eating!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
		pthread_mutex_unlock(philo->forks[1]);
		pthread_mutex_unlock(philo->forks[0]);
		pthread_mutex_unlock(&(philo->data->mutex));
        usleep(philo->time_eat * 1000);
	}
    philo->condition = SLEEPING;
	if (philo->condition == SLEEPING)
	{
		printf("%ld Philosofer %d is sleeping!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
		usleep(philo->time_sleep * 1000);
	}
	philo->condition = THINKING;
	printf("%ld Philosofer %d is thinking!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
	
}



int main(int argc, char **argv)
{
    t_data  *data;
    t_philo	**philo;
    int i;

    i = -1;
    data = new_data(argv);
    philo = malloc(atoi(argv[1]) * sizeof(t_philo*));
    while (++i < atoi(argv[1]))
	{
        philo[i] = new_philo(data, argv, i);
        pthread_create(&philo[i]->thread, NULL, &routine, (void *)(philo[i]));
	}
    i = -1;
    while (++i < atoi(argv[1]))
        pthread_join(philo[i]->thread, NULL);
    free_forks(data);    
//	pthread_mutex_destroy(&data->mutex);
//	pthread_mutex_destroy(&data->mutexSleep);
    return (0);
}
