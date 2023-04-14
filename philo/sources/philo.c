/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:12:09 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/14 17:44:14 by vkist-si         ###   ########.fr       */
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

void *check_death(void *arg)
{
	t_philo *philo;
	int i;
	
	i = -1;	
	philo = (t_philo*)arg;
	while (++i < philo->data->tot)
	{
		//pthread_mutex_lock(&(philo->data->mutex));
		if ((get_time_in_ms() - philo->data->last_meal) > philo->time_die)
		{		
		//	pthread_mutex_unlock(&(philo->data->mutex));
			printf("Dead.\n");
			return (NULL);
		}
	//	pthread_mutex_unlock(&(philo->data->mutex));
	}
}

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
	
	take_fork(philo);
	pthread_mutex_lock(&(philo->data->mutex_last_meal));
    printf("%ld Philosofer %d is eating!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
	pthread_mutex_unlock(&(philo->data->mutex_last_meal));
    usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(philo->forks[1]);
	pthread_mutex_unlock(philo->forks[0]);
	printf("%ld Philosofer %d is sleeping!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
	usleep(philo->time_sleep * 1000);
	printf("%ld Philosofer %d is thinking!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
}

int main(int argc, char **argv)
{
    t_data  *data;
    t_philo	**philo;
    int i;
	pthread_t	monitoring_thread;
	
    i = -1;
    data = new_data(argv);
    philo = malloc(atoi(argv[1]) * sizeof(t_philo*));
    while (++i < atoi(argv[1]))
	{
        philo[i] = new_philo(data, argv, i);
        pthread_create(&philo[i]->thread, NULL, &routine, (void *)(philo[i]));
	}
    i = -1;
	pthread_create(&monitoring_thread, NULL, &check_death, &philo);
	pthread_join(monitoring_thread, NULL);
    while (++i < atoi(argv[1]))
        pthread_join(philo[i]->thread, NULL);
	//create monitoring thread
    free_forks(data);    
	pthread_mutex_destroy(&data->mutex);
//	pthread_mutex_destroy(&data->mutexSleep);
    return (0);
}
