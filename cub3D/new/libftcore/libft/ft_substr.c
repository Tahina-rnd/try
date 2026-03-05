/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 07:24:28 by tarandri          #+#    #+#             */
/*   Updated: 2025/03/11 09:08:38 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	d = malloc(sizeof(char) * len + 1);
	if (!d)
		return (NULL);
	i = 0;
	while ((start + i) < ft_strlen(s) && i < len)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
