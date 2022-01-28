/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvidon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:14:07 by cvidon            #+#    #+#             */
/*   Updated: 2022/01/26 14:15:55 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*newline(char *temp)
{
	size_t	i;

	i = 0;
	if (temp[i] == '\0')
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	return (ft_substr_gnl(temp, 0, i));
}

char	*newtemp(char *temp)
{
	char	*new;
	size_t	i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
		return (free(temp), NULL);
	if (temp[i] == '\n')
		i++;
	new = ft_substr_gnl(temp, i, ft_strlen_gnl(temp) - i);
	return (free(temp), new);
}

char    *get_next_line(int fd)
{
	static char *temp[1024];
	char        *line;
	char        *buf;
	long        r;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	r = 1;
	while (r && !ft_has_nl(temp[fd]))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(buf), NULL);
		buf[r] = '\0';
		temp[fd] = ft_strjoin_gnl(temp[fd], buf);
	}
	free(buf);
	if (!temp[fd])
		return (NULL);
	line = newline(temp[fd]);
	temp[fd] = newtemp(temp[fd]);
	return (line);
}
