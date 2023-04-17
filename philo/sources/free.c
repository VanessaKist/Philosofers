/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:31 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/15 22:57:53 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_forks(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->tot)
	{
		pthread_mutex_destroy(data->forks[index]);
		index++;
	}
	free(data->forks);
}
