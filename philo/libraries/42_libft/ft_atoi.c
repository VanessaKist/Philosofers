/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:29:06 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/12/07 00:49:59 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	check_return(long int nbr, int sign, t_bool *error)
{
	if ((nbr > 2147483647) || (nbr < -2147483648))
		return (0);
	else
	{
		*error = FALSE;
		return ((int)nbr * sign);
	}
}

long int	ft_atoi(const char *str, t_bool *error)
{
	long int	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if ((*str == 45) || (*str == 43))
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		nbr = (nbr * 10) + (*str - 48);
		str++;
	}
	return (check_return(nbr, sign, error));
}
