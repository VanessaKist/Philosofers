/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:18:50 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/27 00:13:53 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	create_thread(char **argv, t_philo *philo)
{
	pthread_t	*thread;
	pthread_t	monitoring_thread;
	int			i;

	thread = ft_calloc(sizeof(pthread_t), ft_atoi(argv[1]));
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
