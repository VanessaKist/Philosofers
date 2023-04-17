/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:12:09 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/17 19:11:34 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
    t_data  *data;
    t_philo	*philo;
    int i;

    i = 0;
    (void)argc;
    data = new_data(argv);
    philo = new_philo(data, argv, 0);
   
	create_thread(data, argv, philo);
  //  free_forks(data);    
	//pthread_mutex_destroy(&data->mutex_last_meal);
   // pthread_mutex_destroy(&data->mutex_eat);
    return (0);
}
