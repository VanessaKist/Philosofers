/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:35:21 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/21 17:08:22 by vkist-si         ###   ########.fr       */
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
} t_philo;

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
    printf("%ld Philosofer %d is eating!\n", philo->time_eat, philo->id);
    printf("%ld Philosofer %d is sleeping!\n", philo->time_sleep, philo->id);
    printf("Philosofer %d is thinking!\n", philo->id);
}

int main(int argc, char **argv)
{
    pthread_t myThread;
    pthread_t myThread2;

    t_philo *philo;
    philo = malloc(sizeof(t_philo) * 2);


    philo->time_eat = atoi(argv[1]);
    philo->time_sleep = atoi(argv[2]);
    philo->id = 1;
    pthread_create(&myThread, NULL, &routine, (void *)(philo));
    pthread_join(myThread, NULL);
    philo->id = 2;
    pthread_create(&myThread2, NULL, &routine, (void *)(philo));
    pthread_join(myThread2, NULL);
    return (0);
}
