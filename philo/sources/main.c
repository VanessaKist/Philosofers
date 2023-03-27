/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:35:21 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/27 19:01:45 by vkist-si         ###   ########.fr       */
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
    int     left_hand_fork;
    int     right_hand_fork;
    pthread_t thread;
    time_t	time_eat;
	time_t	time_sleep;
    time_t  time_die;
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

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
    if (philo->left_hand_fork == 1 && philo->right_hand_fork == 1)
    {
        printf("%ld Philosofer %d is eating!\n", philo->time_spended, philo->id);
        philo->time_spended = eat(philo);
      //  philo->left_hand_fork = 0;
      //  philo->right_hand_fork = 0;
    }
    printf("%ld Philosofer %d is sleeping!\n", philo->time_spended, philo->id);
    philo->time_spended = sleep(philo);
    printf("%ld Philosofer %d is thinking!\n", philo->time_spended, philo->id);
}

t_philo	*new_philo(char **argv, int i)
{
	t_philo	*philo;
    
    philo = malloc(sizeof(t_philo));
    philo->time_spended = 0;
    philo->time_eat = atoi(argv[2]);
    philo->time_sleep = atoi(argv[3]);
    philo->time_die = atoi(argv[4]);
    philo->id = i + 1;
    philo->left_hand_fork = 1;
    philo->right_hand_fork = 1;
    philo->thread = malloc(sizeof(pthread_t));
	return (philo);
}

int main(int argc, char **argv)
{
    pthread_t myThread;
    pthread_t myThread2;
    time_t	last_meal;
    t_philo	*philo;
    int i;

    i = -1;   
    while (i++ < atoi(argv[1]))
    {
        philo = new_philo(argv, i);
        pthread_create(&philo->thread, NULL, &routine, (void *)(philo));        
        pthread_join(philo->thread, NULL);
    }
    last_meal = get_time_in_ms();
   // pthread_create(&myThread, NULL, &routine, (void *)(philo));
 //   pthread_create(&myThread2, NULL, &routine, (void *)(philo));
    //pthread_join(myThread2, NULL);
    return (0);
}

// 0 Philosopher 1 is eating
// 200 Philosopher 1 is sleeping
// 200 Philosopher 2 is eating
// 300 Philosopher 1 is thinking
// 400 Philosopher 2 is sleeping
// 500 Philosopher 2 is thinking