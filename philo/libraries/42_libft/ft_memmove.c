/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:45:59 by coder             #+#    #+#             */
/*   Updated: 2022/09/17 20:59:48 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * n);
	if (temp == NULL)
		return (NULL);
	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	free (temp);
	return (dest);
}
