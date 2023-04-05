/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:48:56 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/04 22:51:36 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
int fuel = 50;

void *routine(void* args) {
	pthread_mutex_lock(&mutexFuel);
	fuel += 50;
	pthread_mutex_unlock(&mutexFuel);
}

int main (void)
{
	pthread_t th[THREAD_NUM];
	pthread_mutex_init(&mutexFuel, NULL);
	int i;
	for (i = 0; i < THREAD_NUM; i++) {
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
			perror("Failed to create thread.");
		}
	}
	for (i = 0; i < THREAD_NUM; i++) {
		if(pthread_join(th[i], NULL) != 0) {
			perror("Failed to create thread.");
		}
	}
	printf("Fuel: %d\n", fuel);
	//printf("Water: %d\n", water);
    pthread_mutex_destroy(&mutexFuel);
    //pthread_mutex_destroy(&mutexWater);
	return 0;
}

