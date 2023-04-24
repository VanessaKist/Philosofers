/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:54:48 by vkist-si          #+#    #+#             */
/*   Updated: 2023/04/24 17:50:23 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	has_word(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int check_input(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!has_word(argv[i]))
			return (1);
		i++;
	}
	return 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = 0;
	if (!size || !count)
		return (malloc(0));
	if (size > 2147483647 / count)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (p);
	while (i < size * count)
		p[i++] = '\0';
	return (p);
}