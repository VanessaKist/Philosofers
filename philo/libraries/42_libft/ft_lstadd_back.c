/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:05:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/10/13 20:42:19 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_element **stack, t_element *new)
{
	t_element	*last;

	if (!stack || !new)
		return ;
	last = ft_lstlast(*stack);
	if (last != NULL)
		last->next = new;
	else
		*stack = new;
}
