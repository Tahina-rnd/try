/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:46:16 by maminran          #+#    #+#             */
/*   Updated: 2026/02/27 01:07:20 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_rectangle(t_data *data, int x, int y, int color)
{
	char	*image;
	int		offset;
	int		hor;
	int		ver;

	ver = 0;
	while (ver < TILE_SIZE)
	{
		hor = 0;
		while (hor < TILE_SIZE)
		{
			offset = (y + ver) * data->img.line_length + (x + hor)
				* (data->img.bits_per_pixel / 8);
			image = data->img.addr + offset;
			*(unsigned int *)image = color;
			hor++;
		}
		ver++;
	}
}

void	draw_line(t_data *data, t_pos point_A, t_pos point_B, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	cur_x;
	double	cur_y;

	delta_x = point_B.x - point_A.x;
	delta_y = point_B.y - point_A.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	cur_x = point_A.x;
	cur_y = point_A.y;
	while (pixels > 0)
	{
		pixel_put(data, (int)cur_x, (int)cur_y, color);
		cur_x += delta_x;
		cur_y += delta_y;
		pixels--;
	}
}

void	draw_filled_player(t_data *data, t_pos point, int color)
{
	double	size;
	double	i;
	t_pos	target;

	size = 6.0;
	i = -2.5;
	while (i <= 2.5)
	{
		target.x = data->pos.x + cos(data->angle + i) * size;
		target.y = data->pos.y + sin(data->angle + i) * size;
		draw_line(data, point, target, color);
		i += 0.01;
	}
}

void	draw_player(t_data *data, int color)
{
	double	size;
	t_pos	point_A;
	t_pos	point_B;
	t_pos	point_C;

	size = 1.0;
	point_A.x = data->pos.x + cos(data->angle) * size;
	point_A.y = data->pos.y + sin(data->angle) * size;
	point_B.x = data->pos.x + cos(data->angle) * size;
	point_B.y = data->pos.y + sin(data->angle) * size;
	point_C.x = data->pos.x + cos(data->angle) * size;
	point_C.y = data->pos.y + sin(data->angle) * size;
	draw_filled_player(data, point_A, color);
	draw_filled_player(data, point_B, color);
	draw_filled_player(data, point_C, color);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*image;
	int		offset;

	if (x < 0 || x >= data->screen.width || y < 0 || y >= data->screen.height)
		return ;
	offset = y * data->img.line_length + x * (data->img.bits_per_pixel / 8);
	image = data->img.addr + offset;
	*(unsigned int *)image = color;
}

static void	draw_wall(t_data *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_rectangle(data, x * TILE_SIZE, y * TILE_SIZE, PURPLE);
			x++;
		}
		y++;
	}
}

// static void	draw_rayon(t_data *data)
// {
// 	int		i;
// 	double	ray_x;
// 	double	ray_y;

// 	i = 0;
// 	while (1)
// 	{
// 		ray_x = data->pos.x + cos(data->angle) * i;
// 		ray_y = data->pos.y + sin(data->angle) * i;
// 		if (data->map[(int)ray_y / TILE_SIZE][(int)ray_x / TILE_SIZE] != '1')
// 			pixel_put(data, (int)ray_x, (int)ray_y, GREEN);
// 		else
// 			break ;
// 		i++;
// 	}
// }

void	draw_minimap(t_data *data)
{
	draw_wall(data);
	// draw_rayon(data);
	draw_player(data, GREEN);
}
