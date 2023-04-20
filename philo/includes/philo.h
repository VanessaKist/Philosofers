/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:33:45 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/19 18:50:40 by vkist-si         ###   ########.fr       */
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

// enum e_philo_condition {
// EATING,
// SLEEPING,
// THINKING
// };

#define EAT 1
#define THINK 2
#define SLEEP 3
#define FORK1 4
#define FORK2 5
#define DEAD 6

typedef pthread_mutex_t t_fork;

typedef pthread_mutex_t	t_mutex;

typedef struct s_data
{
	time_t  death;
    time_t  time_spended;
	int		tot;
	time_t	start_time;
	int		flag;
	t_fork	**forks;
	t_mutex mutex_last_meal;
	t_mutex mutex_eat;
	t_mutex mutex_stop;
	t_mutex mutex_meals;
	t_mutex mutex_monitor;
	t_mutex mutex_print;
	t_mutex mutex_flag;
} t_data;

typedef struct s_philo
{    
	time_t	last_meal;
	int	    id;
	int	    tot;
	int 	condition;
    time_t	time_eat;
	time_t	time_sleep;
    time_t  time_die;
	int		meals;
	int 	meals_done;
	t_fork	**forks;
    t_data	*data;
} t_philo;

time_t	get_time_in_ms(void);
time_t  eat_philo(t_philo *philo);
void  	sleep_philo(t_philo *philo);
t_philo	*new_philo(t_data *data, char **argv, int i);
t_data	*new_data(char **argv);
t_fork	**init_forks(t_data *data);
void 	get_forks(t_philo *philo);
void	free_forks(t_data *data);
void 	*check_death(void *arg);
void 	create_thread(t_data *data, char **argv, t_philo *philo);
void 	*routine(void * arg);
long 	get_last_meal(t_philo *philo);
void 	print_actions(t_philo *philo, int flag);
int		is_dinner_over(t_philo *philo);

#endif