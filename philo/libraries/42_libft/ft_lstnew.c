/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:51:41 by vkist-si          #+#    #+#             */
/*   Updated: 2022/11/25 20:36:06 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_lstnew(int content, int stack_pos)
{
	t_element	*new;

	new = (t_element *)ft_calloc(1, sizeof(t_element));
	new->content = content;
	new->stack_pos = stack_pos;
	new->next = NULL;
	return (new);
}
