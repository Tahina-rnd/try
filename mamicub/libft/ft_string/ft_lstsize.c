/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:41:04 by maminran          #+#    #+#             */
/*   Updated: 2025/05/19 12:40:21 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
