/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:30:14 by tarandri          #+#    #+#             */
/*   Updated: 2025/05/12 12:54:53 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_tmp;
	size_t	i;
	size_t	j;

	new_tmp = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!new_tmp)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		new_tmp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		new_tmp[i++] = s2[j++];
	new_tmp[i] = '\0';
	free(s1);
	return (new_tmp);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*new_line;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen_gnl(s))
		return (NULL);
	if (ft_strlen_gnl(s + start) < len)
		len = ft_strlen_gnl(s + start);
	new_line = malloc(sizeof(char) * len + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_line[i] = s[start + i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}
