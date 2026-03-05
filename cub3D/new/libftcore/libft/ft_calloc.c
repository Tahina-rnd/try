/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:30:27 by tarandri          #+#    #+#             */
/*   Updated: 2025/03/18 10:38:07 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nw;

	if (size != 0 && nmemb > ((size_t)-1 / size))
		return (NULL);
	nw = (void *)malloc(size * nmemb);
	if (!nw)
		return (NULL);
	ft_bzero(nw, (size * nmemb));
	return (nw);
}
