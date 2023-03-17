/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:06:44 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/17 20:54:01 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_htoi(char s[])
{
	int	val;
	int	i;

	val = 0;
	i = 0;
	if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
		i += 2;
	while (s[i])
	{
		if (val > INT_MAX)
			return (0);
		else if (s[i] >= '0' && s[i] <= '9')
			val = val * 16 + s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'F')
			val = val * 16 + s[i] - 'A' + 10;
		else if (s[i] >= 'a' && s[i] <= 'f')
			val = val * 16 + s[i] - 'a' + 10;
		else
			return (0);
		i++;
	}
	return (val);
}
