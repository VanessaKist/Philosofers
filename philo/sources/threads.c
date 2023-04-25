/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:18:50 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/25 17:00:17 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void create_thread(t_data *data, char **argv, t_philo *philo)
{

    int i;
    (void)data;
    pthread_t	*thread;
	pthread_t	monitoring_thread;
    thread = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
    i = 0;
    while (i < ft_atoi(argv[1]))
    {
        pthread_create(&thread[i], NULL, routine, &philo[i]);
        i++;
    }
    i = 0;
	pthread_create(&monitoring_thread, NULL, check_death, philo);
    while (i < ft_atoi(argv[1]))
    {
        pthread_join(thread[i], NULL);
        i++;
    }
	pthread_join(monitoring_thread, NULL);
    free(thread);
}