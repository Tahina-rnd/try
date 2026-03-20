/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:43:54 by maminran          #+#    #+#             */
/*   Updated: 2025/05/19 12:39:18 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_bzero(void *s, size_t n)
{
	char	*cast;
	size_t	i;

	cast = (char *) s;
	i = 0;
	while (i < n)
	{
		cast[i] = 0;
		i++;
	}
}
