/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:12:09 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/05 00:43:50 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *routine(void * arg)
{
    t_philo *philo;
    
    philo = (t_philo*)arg;
    if (philo->data->left_hand_fork == 1 && philo->data->right_hand_fork == 1)
    {
        printf("%ld Philosofer %d is eating!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
        usleep(philo->time_eat * 1000);
 
      //  philo->data->left_hand_fork = 0;
     //   philo->data->right_hand_fork = 0;
    }
    printf("%ld Philosofer %d is sleeping!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
    usleep(philo->time_sleep * 1000);
	// if philosofars ja comeu entao
		//think e passe garfos para proximo

}

int main(int argc, char **argv)
{
    t_data  *data;
    t_philo	**philo;
    int i;

    i = -1;
    philo = malloc(atoi(argv[1]) * sizeof(t_philo*));
    data = new_data(argv);
    while (++i < atoi(argv[1]))
    {
        philo[i] = new_philo(data, argv, i);
        pthread_create(&philo[i]->thread, NULL, &routine, (void *)(philo[i]));        
    }
    i = -1;
    while (++i < atoi(argv[1]))
        pthread_join(philo[i]->thread, NULL);
    return (0);
}

// 0 Philosopher 1 is eating
// 200 Philosopher 1 is sleeping
// 200 Philosopher 2 is eating
// 300 Philosopher 1 is thinking
// 400 Philosopher 2 is sleeping
// 500 Philosopher 2 is thinking    