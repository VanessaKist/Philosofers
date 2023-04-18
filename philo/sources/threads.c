/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:18:50 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/18 15:06:51 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void create_thread(t_data *data, char **argv, t_philo *philo)
{

    int i;
    (void)data;
    pthread_t	*thread;
	pthread_t	monitoring_thread;
    thread = malloc(sizeof(pthread_t) * atoi(argv[1]));
    i = 0;
    while (i < atoi(argv[1]))
    {
        pthread_create(&thread[i], NULL, routine, &philo[i]);
        i++;
    }
    i = 0;
	pthread_create(&monitoring_thread, NULL, check_death, philo);
    while (i < atoi(argv[1]))
    {
        pthread_join(thread[i], NULL);
        i++;
    }
	pthread_join(monitoring_thread, NULL);
}