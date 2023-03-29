/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:12:09 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/29 17:49:17 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
    if (philo->left_hand_fork == 1 && philo->right_hand_fork == 1)
    {
        printf("%ld Philosofer %d is eating!\n", philo->time_spended, philo->id);
        philo->time_spended = eat(philo);
      //philo->left_hand_fork = 0;
      //philo->right_hand_fork = 0;
    }
    printf("%ld Philosofer %d is sleeping!\n", (philo->time_spended - philo->data->last_meal), philo->id);
    philo->time_spended = sleep_philo(philo);
	// if philosofars ja comeu entao
		//think e passe garfos para proximo
    printf("%ld Philosofer %d is thinking!\n", (philo->time_spended - philo->data->last_meal), philo->id);
}

int main(int argc, char **argv)
{
    pthread_t myThread;
    pthread_t myThread2;
    t_data  *data;
    t_philo	*philo;
    int i;

    i = -1;
    data = new_data(argv);
    printf("data->last_meal: %ld\n data->death: %ld\n", data->last_meal, data->death);
    while (++i < atoi(argv[1]))
    {
        philo = new_philo(data, argv, i);
        pthread_create(&philo->thread, NULL, &routine, (void *)(philo));        
        pthread_join(philo->thread, NULL);
    }
    return (0);
}

// 0 Philosopher 1 is eating
// 200 Philosopher 1 is sleeping
// 200 Philosopher 2 is eating
// 300 Philosopher 1 is thinking
// 400 Philosopher 2 is sleeping
// 500 Philosopher 2 is thinking    