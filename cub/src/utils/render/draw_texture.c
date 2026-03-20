/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:53:22 by maminran          #+#    #+#             */
/*   Updated: 2026/03/20 22:07:27 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_texture_on_window(t_data *data, int x, t_var *utils, t_img *tex)
{
	int				y;
	unsigned int	color;

	y = 0;
	while (y < data->screen.height)
	{
		if (y < utils->draw_start)
			pixel_put(data, x, y, data->cub.ceiling);
		else if (y <= utils->draw_end)
		{
			utils->tex_y = (int)utils->tex_pos % tex->size.height;
			color = get_pixel_color(tex, utils->tex_x, utils->tex_y);
			pixel_put(data, x, y, color);
			utils->tex_pos += utils->step;
		}
		else
			pixel_put(data, x, y, data->cub.floor);
		y++;
	}
}

void	render_3d(t_data *data)
{
	int		x;
	double	ray_angle;
	t_img	*tex;
	t_var	utils;

	x = 0;
	while (x < data->screen.width)
	{
		ray_angle = (data->angle - 0.5) + ((double)x / data->screen.width);
		utils.fish_eye = get_dist(data, ray_angle) * cos(ray_angle
				- data->angle);
		utils.line_h = (int)(data->screen.height * TILE_SIZE / utils.fish_eye);
		tex = get_texture(data, ray_angle, data->side);
		utils.tex_x = part_start(data, tex, ray_angle);
		get_start_end(data, &utils, tex);
		if (((data->screen.height / 2) + (utils.line_h
					/ 2)) >= data->screen.height)
			utils.draw_end = data->screen.height - 1;
		else
			utils.draw_end = (data->screen.height / 2) + (utils.line_h / 2);
		put_texture_on_window(data, x, &utils, tex);
		x++;
	}
}
