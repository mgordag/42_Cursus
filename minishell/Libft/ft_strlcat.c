/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag <mgordag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:22:59 by mgordag           #+#    #+#             */
/*   Updated: 2022/10/18 11:23:00 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	value;
	size_t	dlen;
	size_t	slen;

	if (size == 0)
		return (ft_strlen(src));
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size < dlen)
		value = slen + size;
	else
		value = dlen + slen;
	i = 0;
	while (src[i] && (dlen + i) + 1 < size)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (value);
}
