/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:01:38 by vkist-si          #+#    #+#             */
/*   Updated: 2022/09/17 21:01:41 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	cat = (char *)ft_calloc(len, sizeof(char));
	if (!cat)
		return (NULL);
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		cat[i] = s2[j];
		j++;
		i++;
	}
	cat[i] = 0;
	return (cat);
}
