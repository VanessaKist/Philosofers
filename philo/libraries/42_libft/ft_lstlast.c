/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:04:08 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/10/27 02:30:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element	*ft_lstlast(t_element *element)
{
	if (element == NULL)
		return (NULL);
	while (element->next != NULL)
		element = element->next;
	return (element);
}
