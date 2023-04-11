/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:12:09 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/11 20:39:06 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void get_forks(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->left_fork);
//     printf("%ld Philosofer %d has taken a fork.\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
//     printf("%ld Philosofer %d has taken a fork.\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
// 	pthread_mutex_lock(philo->right_fork);
// }

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
	
	if (philo->condition == THINKING)
	{
	//	pthread_mutex_lock(&philo->data->mutexEat);
	//	get_forks(philo);
		philo->condition = EATING;
        printf("%ld Philosofer %d is eating!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
        usleep(philo->time_eat * 1000);
	//	pthread_mutex_unlock(philo->left_fork);
	//  pthread_mutex_unlock(philo->right_fork);
	//	pthread_mutex_unlock(&philo->data->mutexEat);
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

void assing_fork(t_philo *philo, int i)
{
    if (i == 0)
		philo->fork_r = philo[philo->data->tot].fork_l;
	else
 		philo->fork_r = philo[i - 1].fork_l;
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
        philo[i] = new_philo(data, argv, i);
    i = -1;
    while (++i < atoi(argv[1]))
        assing_fork(*philo, i);       
    i = -1;
    while (++i < atoi(argv[1]))
        pthread_create(&philo[i]->thread, NULL, &routine, (void *)(philo[i]));
    i = -1;
    while (++i < atoi(argv[1]))
        pthread_join(philo[i]->thread, NULL);
   // free_forks(data);    
//	pthread_mutex_destroy(&data->mutexEat);
//	pthread_mutex_destroy(&data->mutexSleep);
    return (0);
}

// 0 Philosopher 1 is eating
// 200 Philosopher 1 is sleeping
// 200 Philosopher 2 is eating
// 300 Philosopher 1 is thinking
// 400 Philosopher 2 is sleeping
// 500 Philosopher 2 is thinking    