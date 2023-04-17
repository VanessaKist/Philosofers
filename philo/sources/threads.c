/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:18:50 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/16 00:31:15 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void create_thread(t_data *data, char **argv)
{
	t_philo	**philo;
    int i;
	pthread_t	monitoring_thread;
	
    i = -1;
    philo = malloc(atoi(argv[1]) * sizeof(t_philo*));
    while (++i < atoi(argv[1]))
	{
        philo[i] = new_philo(data, argv, i);
        pthread_create(&philo[i]->thread, NULL, routine, (void *)(philo[i]));
	}
    i = -1;
	pthread_create(&monitoring_thread, NULL, &check_death, &philo);
    while (++i < atoi(argv[1]))
        pthread_join(philo[i]->thread, NULL);
	pthread_join(monitoring_thread, NULL);
}