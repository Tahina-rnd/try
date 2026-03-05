/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:53:22 by maminran          #+#    #+#             */
/*   Updated: 2026/03/01 20:36:17 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_v_line(t_data *data, int x, int line_h, int tex_x)
{
	int				y;
	int				start;
	int				end;
	unsigned int	color;
	int				tex_y;

	start = (data->screen.height / 2) - (line_h / 2);
	if (start < 0)
		start = 0;
	end = (data->screen.height / 2) + (line_h / 2);
	if (end >= data->screen.height)
		end = data->screen.height - 1;
	y = 0;
	while (y < data->screen.height)
	{
		if (y < start)
			pixel_put(data, x, y, 0x333333);
		else if (y >= start && y <= end)
		{
			tex_y = (y - (data->screen.height / 2 - line_h / 2))
				* data->texture.size.height / line_h;
			color = get_pixel_color(data, tex_x, tex_y);
			pixel_put(data, x, y, color);
		}
		else
			pixel_put(data, x, y, 0x666666);
		y++;
	}
}

void	render_3d(t_data *data)
{
	int		x;
	double	rayon;
	double	dist;
	double	dist_corrigee;
	int		line_h;
	int		tex_x;
	double	hit_x;
	double	hit_y;
	double	reste_x;
	double	reste_y;

	x = 0;
	while (x < data->screen.width)
	{
		rayon = (data->angle - 0.5) + ((double)x / data->screen.width);
		dist = get_dist(data, rayon);
		dist_corrigee = dist * cos(rayon - data->angle);
		line_h = (int)(data->screen.height * TILE_SIZE / dist_corrigee);
		hit_x = data->pos.x + cos(rayon) * dist;
		hit_y = data->pos.y + sin(rayon) * dist;
		reste_x = fmod(hit_x, TILE_SIZE);
		reste_y = fmod(hit_y, TILE_SIZE);
		if (reste_x < 0.1 || reste_x > TILE_SIZE - 0.1)
		{
			tex_x = (int)(reste_y * data->texture.size.width / TILE_SIZE);
			if (cos(rayon) < 0)
				tex_x = data->texture.size.width - tex_x - 1;
		}
		else
		{
			tex_x = (int)(reste_x * data->texture.size.width / TILE_SIZE);
			if (sin(rayon) > 0)
				tex_x = data->texture.size.width - tex_x - 1;
		}
		draw_v_line(data, x, line_h, tex_x);
		x++;
	}
}
