/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:24:31 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/29 18:30:16 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t  eat_philo(t_philo *philo)
{
    philo->data->time_spended += philo->time_eat;
    if (philo->data->time_spended > philo->data->death)
    {
        printf("Dead by eat\n");
        exit(0);   
    }    
    else
        return(philo->data->time_spended);
}

time_t  sleep_philo(t_philo *philo)
{
    philo->data->time_spended += philo->time_sleep;
    if (philo->data->time_spended > philo->data->death)
    {
        printf("Dead by sleep\n");
        exit(0);   
    }    
    else
        return(philo->data->time_spended);
}