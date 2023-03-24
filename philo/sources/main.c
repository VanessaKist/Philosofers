/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:35:21 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/24 14:25:24 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

typedef struct s_philo
{
	int	    id;
	int	    tot;
    time_t	time_eat;
	time_t	time_sleep;
    time_t  time_die;
    time_t  time_think;
    time_t	last_meal;
    time_t  death;
    time_t  time_spended;
} t_philo;

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

time_t  eat(t_philo *philo)
{
    return(philo->time_spended + philo->time_eat);
}

time_t  sleep(t_philo *philo)
{
    return(philo->time_spended + philo->time_sleep);
}

time_t  think(t_philo *philo)
{
    return(philo->time_spended + philo->time_think);
}

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
    philo->time_spended = eat(philo);
    printf("%ld Philosofer %d is eating!\n", philo->time_spended, philo->id);
    philo->time_spended = sleep(philo);
    printf("%ld Philosofer %d is sleeping!\n", philo->time_spended, philo->id);
    philo->time_spended = think(philo);
    printf("%ld Philosofer %d is thinking!\n", philo->time_spended, philo->id);
}

int main(int argc, char **argv)
{
    pthread_t myThread;
    pthread_t myThread2;

    t_philo *philo;
    philo = malloc(sizeof(t_philo) * 2);
    
    philo->time_spended = 0;
    philo->last_meal = get_time_in_ms();
    philo->time_eat = atoi(argv[1]);
    philo->time_sleep = atoi(argv[2]);
    philo->time_think = atoi(argv[3]);
    philo->id = 1;
    pthread_create(&myThread, NULL, &routine, (void *)(philo));
    pthread_join(myThread, NULL);
    philo->time_spended = 0;
    philo->id = 2;
    pthread_create(&myThread2, NULL, &routine, (void *)(philo));
    pthread_join(myThread2, NULL);
    return (0);
}
