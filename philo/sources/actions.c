/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:24:31 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/28 17:40:50 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t  eat(t_philo *philo)
{
    philo->time_spended += philo->time_eat;
    if (philo->time_spended >= philo->time_die)
        return(printf("Dead."));   
    else
        return(philo->time_spended);
}

time_t  sleep_philo(t_philo *philo)
{
    philo->time_spended += philo->time_sleep;
    if (philo->time_spended >= philo->time_die)
        return(printf("Dead\n"));   
    else
        return(philo->time_spended);
}