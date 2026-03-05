/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:29:53 by tarandri          #+#    #+#             */
/*   Updated: 2025/03/19 07:15:24 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_l;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	len_l = ft_strlen(little);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && (big[i + j] == little[j] && i + j < len))
			j++;
		if (j == len_l)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
