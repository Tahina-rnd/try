/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:41:54 by maminran          #+#    #+#             */
/*   Updated: 2026/02/26 19:35:19 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	laterale(t_data *data)
{
	if (data->move.left)
	{
		data->pos.x += sin(data->angle) * SPEED / 2;
		data->pos.y -= cos(data->angle) * SPEED / 2;
	}
	if (data->move.right)
	{
		data->pos.x -= sin(data->angle) * SPEED / 2;
		data->pos.y += cos(data->angle) * SPEED / 2;
	}
}

void	walk(t_data *data)
{
	if (data->move.forward)
	{
		data->pos.x += cos(data->angle) * SPEED;
		data->pos.y += sin(data->angle) * SPEED;
	}
	if (data->move.back)
	{
		data->pos.x -= cos(data->angle) * SPEED;
		data->pos.y -= sin(data->angle) * SPEED;
	}
}

void	rotating(t_data *data)
{
	if (data->look.left)
		data->angle -= SENSIVITY;
	if (data->look.right)
		data->angle += SENSIVITY;
	if (data->angle < 0)
		data->angle += 2 * M_PI;
	if (data->angle > 2 * M_PI)
		data->angle -= 2 * M_PI;
}
