/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:54:58 by vkist-si          #+#    #+#             */
/*   Updated: 2022/09/17 20:55:02 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrixfree(void **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}
