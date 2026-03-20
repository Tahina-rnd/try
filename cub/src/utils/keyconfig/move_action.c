/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:41:54 by maminran          #+#    #+#             */
/*   Updated: 2026/03/19 01:34:25 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_collision(double move_x, double move_y, double *offset_x,
		double *offset_y)
{
	if (move_x > 0)
		*offset_x = COLLISION;
	else
		*offset_x = -COLLISION;
	if (move_y > 0)
		*offset_y = COLLISION;
	else
		*offset_y = -COLLISION;
}

void	check_collision(t_data *data, double move_x, double move_y)
{
	double	next_x;
	double	next_y;
	double	offset_x;
	double	offset_y;

	if (data->move.right)
	{
		move_x -= sin(data->angle) * (SPEED / 1.5);
		move_y += cos(data->angle) * (SPEED / 1.5);
	}
	next_x = data->cub.player_x + move_x;
	next_y = data->cub.player_y + move_y;
	set_collision(move_x, move_y, &offset_x, &offset_y);
	if (data->cub.map[(int)data->cub.player_y / TILE_SIZE][(int)(next_x
		+ offset_x) / TILE_SIZE] != '1')
		data->cub.player_x = next_x;
	if (data->cub.map[(int)(next_y + offset_y)
		/ TILE_SIZE][(int)data->cub.player_x / TILE_SIZE] != '1')
		data->cub.player_y = next_y;
}

void	move_player(t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	if (data->move.forward)
	{
		move_x += cos(data->angle) * SPEED;
		move_y += sin(data->angle) * SPEED;
	}
	if (data->move.back)
	{
		move_x -= cos(data->angle) * SPEED;
		move_y -= sin(data->angle) * SPEED;
	}
	if (data->move.left)
	{
		move_x += sin(data->angle) * (SPEED / 1.5);
		move_y -= cos(data->angle) * (SPEED / 1.5);
	}
	check_collision(data, move_x, move_y);
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
