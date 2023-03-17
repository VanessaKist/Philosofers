/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:35:21 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/17 17:04:19 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

void *routine(void * arg)
{
    printf("Hello World!");
}

int main(void)
{
    pthread_t myThread;
    
    pthread_create(&myThread, NULL, &routine, NULL);
    pthread_join(myThread, NULL);
    return 0;
}

