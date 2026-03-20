/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:04:00 by maminran          #+#    #+#             */
/*   Updated: 2025/05/30 16:06:39 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_and_null(char *str)
{
	free(str);
	str = NULL;
}

static char	*read_error(char *temp, char *get_str)
{
	free(temp);
	temp = NULL;
	free(get_str);
	get_str = NULL;
	return (NULL);
}

static char	*read_str(char *my_str, int fd)
{
	char	*get_str;
	ssize_t	byte_of_read;
	char	*temp;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	byte_of_read = 1;
	get_str = malloc(BUFFER_SIZE + 1);
	if (!get_str)
		return (NULL);
	while (byte_of_read > 0)
	{
		temp = ft_str_dup(my_str);
		byte_of_read = read(fd, get_str, BUFFER_SIZE);
		if (byte_of_read == -1)
			return (read_error(temp, get_str));
		free_and_null(my_str);
		get_str[byte_of_read] = '\0';
		my_str = ft_str_join(temp, get_str);
		free_and_null(temp);
		if ((!my_str) || ft_str_chr(get_str, '\n'))
			break ;
	}
	free_and_null(get_str);
	return (my_str);
}

static char	*set_str(char *temp)
{
	char	*line;
	int		i;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\n')
		i++;
	if (temp[i] == '\0')
		return (NULL);
	line = ft_str_dup(&temp[i]);
	temp[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*my_str[1024];

	if (fd < 0)
		return (NULL);
	line = read_str(my_str[fd], fd);
	if (!line)
	{
		free(my_str[fd]);
		my_str[fd] = NULL;
		return (NULL);
	}
	else if (*line == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	my_str[fd] = set_str(line);
	return (line);
}
