/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:59:44 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/17 17:34:27 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


// int have_meals(t_philo *philo)
// {
// 	int i;
// 	i = -1;
// 	(void)philo;
// 		// while (++i < philo->data->tot)
// 	// {
// 	// 	if (philo->meals_done == philo->meals)
// 	// 		return(1);
// 	// }
// 	return(0);
// }

// void *check_death(void *arg)
// {
// 	t_philo *philo;
// 	int i;
	
// 	i = 0;	
// 	philo = (t_philo*)arg;
// 	printf("Total philo: %d\n", philo->data->tot);
// 	// while (1)
// 	// {
// 	// 	if(have_meals(philo) == 1)
// 	// 		break;
// 	// 	while (++i < philo->data->tot)
// 	// 	{
// 	// 		//pthread_mutex_lock(&(philo->data->mutex));
// 	// 		if ((get_time_in_ms() - get_last_meal(&philo[i]) >= philo[i].time_die))
// 	// 		{		
// 	// 		//	pthread_mutex_unlock(&(philo->data->mutex));
// 	// 			printf("Dead.\n");
// 	// 			return (NULL);
// 	// 		}
// 	// 	//	pthread_mutex_unlock(&(philo->data->mutex));
// 	// 	}	
// 	// }
// 	return (NULL);
// }