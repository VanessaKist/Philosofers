/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:27:10 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/30 18:06:40 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h> 

int main (void)
{
    time_t time;
    time_t time2;
    struct timeval	start;
    struct timeval	end;

    int i = 0;
    gettimeofday(&start, NULL);
    time = start.tv_sec;
    while (i < 5)
    {
        i++;    
        usleep(500000);
        gettimeofday(&end, NULL);
        time2 = end.tv_sec;
        
        printf("passou: %ld segundos.\n", (time2 - time));
    }
    return 0;
}