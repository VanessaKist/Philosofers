/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:00:00 by vkist-si          #+#    #+#             */
/*   Updated: 2022/09/17 21:00:04 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pointerfree(void *pointer)
{
	if (!pointer)
		return ;
	free(pointer);
}
