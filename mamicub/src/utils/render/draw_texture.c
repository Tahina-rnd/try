/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:16:46 by maminran          #+#    #+#             */
/*   Updated: 2026/03/01 20:37:41 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	get_pixel_color(t_data *data, int x, int y)
{
	char	*pixel;
	t_img	*texture;

	texture = &data->texture;
	if (x < 0 || x >= data->texture.size.width || y < 0
		|| y >= data->texture.size.height)
		return (NONE);
	pixel = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

double	get_dist(t_data *data, double angle)
{
	double	x;
	double	y;
	double	step_x;
	double	step_y;

	x = data->pos.x;
	y = data->pos.y;
	step_x = cos(angle) * 0.1;
	step_y = sin(angle) * 0.1;
	while (data->map[(int)y / TILE_SIZE][(int)x / TILE_SIZE] != '1')
	{
		x += step_x;
		y += step_y;
	}
	return (sqrt((x - data->pos.x) * (x - data->pos.x) + (y - data->pos.y) * (y
				- data->pos.y)));
}

void	get_texture(t_data *data)
{
	data->texture.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			"texture/way.xpm", &data->texture.size.width,
			&data->texture.size.height);
	data->texture.addr = mlx_get_data_addr(data->texture.img_ptr,
			&data->texture.bits_per_pixel, &data->texture.line_length,
			&data->texture.endian);
}

void	draw_texture(t_data *data, int x_start, int y_start)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < 50)
	{
		x = 0;
		while (x < 50)
		{
			color = get_pixel_color(data, x, y);
			if (color != NONE)
				pixel_put(data, x_start + x, y_start + y, color);
			x++;
		}
		y++;
	}
}
