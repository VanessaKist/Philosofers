/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkist-si <vkist-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:01:45 by vkist-si          #+#    #+#             */
/*   Updated: 2022/09/17 21:01:47 by vkist-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;
	size_t	totlen;
	size_t	aux2;

	i = 0;
	dlen = ft_strlen(d);
	slen = ft_strlen(s);
	aux2 = dlen;
	if (n <= dlen)
		totlen = slen + n;
	if (n > dlen)
	{	
		totlen = dlen + slen;
		while (s[i] && (aux2 + 1) < n)
		{
			d[aux2] = s[i];
			aux2++;
			i++;
		}
		d[aux2] = '\0';
	}
	return (totlen);
}
