/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:07:31 by maminran          #+#    #+#             */
/*   Updated: 2025/05/19 12:40:27 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (*(unsigned char *)(s1 + i) == (*(unsigned char *)(s2
			+ i))))
		i++;
	if (i < n)
	{
		return (*(unsigned char *)(s1 + i) - (*(unsigned char *)(s2 + i)));
	}
	return (0);
}
