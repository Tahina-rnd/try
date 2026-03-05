/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:27:03 by tarandri          #+#    #+#             */
/*   Updated: 2025/05/13 06:08:10 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *tmp)
{
	char		*buffer;
	ssize_t		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while ((ft_strchr_gnl(tmp, '\n') == NULL) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(tmp), NULL);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin_gnl(tmp, buffer);
		if (!tmp)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (tmp);
}

static char	*get_line(char *tmp)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!tmp || !tmp[0])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = ft_substr_gnl(tmp, 0, i);
	return (line);
}

static char	*clean_tmp(char *tmp)
{
	size_t	i;
	char	*new_tmp;

	i = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	new_tmp = ft_substr_gnl(tmp, i + 1, ft_strlen_gnl(tmp + i + 1));
	free(tmp);
	return (new_tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_line(fd, tmp);
	if (!tmp)
		return (NULL);
	line = get_line(tmp);
	tmp = clean_tmp(tmp);
	return (line);
}
