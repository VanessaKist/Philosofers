/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:04:03 by vkist-si          #+#    #+#             */
/*   Updated: 2022/09/17 21:04:06 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	j;

	if (s == 0 || set == 0)
		return (NULL);
	while (*s && ft_strchr(set, *s))
		s++;
	j = ft_strlen(s);
	while (ft_strchr(set, s[j]) && j)
		j--;
	return (ft_substr(s, 0, (j + 1)));
}
