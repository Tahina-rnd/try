/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 07:24:48 by tarandri          #+#    #+#             */
/*   Updated: 2025/03/24 07:01:59 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dlen;
	size_t	i;
	size_t	slen;

	slen = ft_strlen (src);
	dlen = ft_strlen (dst);
	index = dlen;
	i = 0;
	while (src[i] && (i + index + 1) < size)
	{
		dst[index + i] = src[i];
		i++;
	}
	if ((index + i) < size)
		dst[index + i] = '\0';
	if (size <= dlen)
		return (slen + size);
	else
		return (slen + dlen);
}
