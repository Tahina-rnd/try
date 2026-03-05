/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 08:11:34 by maminran          #+#    #+#             */
/*   Updated: 2025/06/14 08:46:04 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	ft_find_c(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != '\0')
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static void	ft_free(char **tab, size_t letter)
{
	size_t	i;

	i = 0;
	while (i < letter)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_create_word(const char *start, const char *end)
{
	size_t	len;
	char	*word;
	size_t	i;

	i = 0;
	len = end - start;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	ft_split_helper(char **str, const char *s, char c)
{
	const char	*begin;
	size_t		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		begin = s;
		while (*s && *s != c)
			s++;
		if (begin != s)
		{
			str[i] = ft_create_word(begin, s);
			if (!str[i])
			{
				ft_free(str, i);
				return ;
			}
			i++;
		}
	}
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**str;

	if (!s)
		return (NULL);
	words = ft_find_c(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	ft_split_helper(str, s, c);
	str[words] = NULL;
	return (str);
}
