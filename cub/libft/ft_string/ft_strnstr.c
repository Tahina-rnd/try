/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:29:25 by maminran          #+#    #+#             */
/*   Updated: 2025/05/19 12:42:39 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cbig;
	char	*clittle;

	i = 0;
	j = 0;
	cbig = (char *)big;
	clittle = (char *)little;
	if (little[j] == '\0')
		return (cbig);
	while (cbig[i] != '\0')
	{
		while (clittle[j] != '\0' && (cbig[i + j] == clittle[j] && (j
					+ i < len)))
		{
			j++;
			if (clittle[j] == '\0')
				return (&cbig[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
