/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:35:21 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/17 18:22:44 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

void *routine(void * arg)
{
    arg = (int*)arg;
    printf("Philosofer %d is eating!\n", arg);
    printf("Philosofer %d is sleeping!\n", arg);
    printf("Philosofer %d is thinking!\n", arg);
}

int main(void)
{
    pthread_t myThread;
    pthread_t myThread2;

    int id1 = 1;
    int id2 = 2;
    
    pthread_create(&myThread, NULL, &routine, (void *)(id1));
    pthread_create(&myThread2, NULL, &routine, (void *)(id2));
    pthread_join(myThread, NULL);
    pthread_join(myThread2, NULL);
    return 0;
}

