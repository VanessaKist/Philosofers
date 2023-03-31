/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:48:20 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/30 19:03:34 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data *new_data(char **argv)
{
    t_data *data;
    
    data = malloc(sizeof(t_data));
    data->last_meal = get_time_in_ms();
    data->time_spended = data->last_meal;
    data->death = data->last_meal + atoi(argv[4]);
    data->left_hand_fork = 1;
    data->right_hand_fork = 1;
    return(data);
}

t_philo	*new_philo(t_data *data, char **argv, int i)
{
	t_philo	*philo;
    
    philo = malloc(sizeof(t_philo));
    philo->time_eat = atoi(argv[2]);
    philo->time_sleep = atoi(argv[3]);
    philo->time_die = atoi(argv[4]);
    philo->id = i + 1;
    philo->data = data;
	return (philo);
}
