/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:24:31 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/07 19:36:13 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// time_t  eat_philo(t_philo *philo)
// {
//     philo->data->time_spended += philo->time_eat;
//     if (philo->data->time_spended > philo->data->death)
//     {
//         printf("Dead by eat\n");
//         exit(0);   
//     }    
//     else
//         return(philo->data->time_spended);
// }

// void  sleep_philo(t_philo *philo)
// {
//     pthread_mutex_lock(&philo->data->mutexSleep);
//     printf("%ld Philosofer %d is sleeping!\n", (get_time_in_ms() - philo->data->last_meal), philo->id);
//     usleep(philo->time_sleep * 1000);
// 	pthread_mutex_unlock(&philo->data->mutexSleep);
// }