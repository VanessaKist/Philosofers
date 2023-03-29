/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:33:45 by vkist-si          #+#    #+#             */
/*   Updated: 2023/03/29 17:57:19 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
#include <string.h>
# include <sys/time.h> 

typedef struct s_data
{
    time_t	last_meal;
	time_t  death;
    time_t  time_spended;
}t_data;

typedef struct s_philo
{
	int	    id;
	int	    tot;	
    int     left_hand_fork;
    int     right_hand_fork;
    pthread_t thread;
    time_t	time_eat;
	time_t	time_sleep;
    time_t  time_die;
    t_data	*data;
} t_philo;

time_t	get_time_in_ms(void);
time_t  eat(t_philo *philo);
time_t  sleep_philo(t_philo *philo);
t_philo	*new_philo(t_data *data, char **argv, int i);
t_data *new_data(char **argv);

#endif