/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 22:05:27 by maminran          #+#    #+#             */
/*   Updated: 2026/03/20 22:07:23 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	*get_texture(t_data *data, double angle, int side)
{
	if (side == HORIZONTAL)
	{
		if (sin(angle) < 0)
			return (&data->texture_no);
		return (&data->texture_so);
	}
	else
	{
		if (cos(angle) < 0)
			return (&data->texture_we);
		return (&data->texture_ea);
	}
}

double	ver_or_hor(t_data *data, double angle)
{
	double	wall_x;

	if (data->side == HORIZONTAL)
		wall_x = data->cub.player_x + get_dist(data, angle) * cos(angle);
	else
		wall_x = data->cub.player_y + get_dist(data, angle) * sin(angle);
	wall_x -= floor(wall_x / TILE_SIZE) * TILE_SIZE;
	return (wall_x / TILE_SIZE);
}

int	part_start(t_data *data, t_img *tex, double angle)
{
	int	tex_x;

	tex_x = (int)(ver_or_hor(data, angle) * (double)tex->size.width);
	if ((data->side == VERTICAL && cos(angle) > 0) || (data->side == HORIZONTAL
			&& sin(angle) < 0))
		tex_x = tex->size.width - tex_x - 1;
	return (tex->size.width - tex_x - 1);
}

void	get_start_end(t_data *data, t_var *utils, t_img *tex)
{
	if (utils->line_h <= 0)
		utils->line_h = 1;
	utils->start = (data->screen.height / 2) - (utils->line_h / 2);
	utils->step = 1.0 * tex->size.height / utils->line_h;
	if (utils->start < 0)
		utils->tex_pos = (0 - utils->start) * utils->step;
	else
		utils->tex_pos = 0;
	if (utils->start < 0)
		utils->draw_start = 0;
	else
		utils->draw_start = utils->start;
}
