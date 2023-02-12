/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgordag  <mgordag@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:59:34 by mgordag           #+#    #+#             */
/*   Updated: 2022/03/01 15:01:41 by mgordag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*move_line(char *str)
{
	char	*dest;

	dest = ft_strchr(str, '\n');
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup(dest + 1);
	else
		dest = NULL;
	free(str);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*dest;
	int			size;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE));
	size = read(fd, buffer, BUFFER_SIZE);
	buffer[size] = '\0';
	while (size > 0)
	{
		if (!str[fd])
			str[fd] = ft_strdup(buffer);
		else
			str[fd] = ft_strjoin(str[fd], buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	free(buffer);
	dest = ft_substr(str[fd], 0, ft_strchr(str[fd], '\n') - str[fd] + 1);
	str[fd] = move_line(str[fd]);
	return (dest);
}
