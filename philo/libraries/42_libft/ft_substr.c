/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:04:15 by vkist-si          #+#    #+#             */
/*   Updated: 2022/09/17 21:04:19 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	truelen;
	unsigned int	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		return (NULL);
	else if (len >= slen)
		truelen = slen - start + 1;
	else
		truelen = len + 1;
	sub = (char *)malloc(truelen);
	if (!sub)
		return (NULL);
	while ((start < slen) && (i < len))
	{
		sub[i] = s[start];
		i++;
		start++;
	}	
	sub[i] = 0;
	return (sub);
}
