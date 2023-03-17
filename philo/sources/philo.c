/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:12:09 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/14 22:45:11 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *routine(void * arg)
{	
	t_philo	*philo;

	philo = (t_philo*)arg;
	printf("HELLO WORLD! THIS IS THREAD %d\n", philo->id);
	return (0);
} 

int main (int argc, char **argv)
{
	t_philo *philos;
	
	int	i;
	int j;
	
	j = atoi(argv[1]);
	philos = malloc(sizeof(t_philo) * j);
	i = 1;
	while (i < 3)
	{
		philos[i].id = i;
	//	philos[i].thread = malloc(sizeof(pthread_t));
		printf("%d\n", philos[i].id);
		i++;
	}
	i = 1;
	for (int i = 0; i < j; i++)
	{
		pthread_create(&philos[i].thread, NULL, &routine, (void *)(philos));
	} 
	//pthread_join(t1, NULL);
	pthread_exit(NULL);
	return (0);
}