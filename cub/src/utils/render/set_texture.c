/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:16:46 by maminran          #+#    #+#             */
/*   Updated: 2026/03/19 01:40:31 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	get_pixel_color(t_img *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= texture->size.width || y < 0 || y >= texture->size.height)
		return (NONE);
	pixel = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
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

double	get_dist(t_data *data, double angle)
{
	double	deltaDistX;
	double	deltaDistY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	int		stepX;
	int		stepY;

	deltaDistX = fabs(1 / cos(angle));
	deltaDistY = fabs(1 / sin(angle));
	mapX = (int)(data->cub.player_x / TILE_SIZE);
	mapY = (int)(data->cub.player_y / TILE_SIZE);
	if (cos(angle) < 0)
	{
		stepX = -1;
		sideDistX = (data->cub.player_x / TILE_SIZE - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - data->cub.player_x / TILE_SIZE) * deltaDistX;
	}
	if (sin(angle) < 0)
	{
		stepY = -1;
		sideDistY = (data->cub.player_y / TILE_SIZE - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - data->cub.player_y / TILE_SIZE) * deltaDistY;
	}
	while (data->cub.map[mapY][mapX] != '1')
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			data->side = VERTICAL;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			data->side = HORIZONTAL;
		}
	}
	if (data->side == VERTICAL)
		return ((sideDistX - deltaDistX) * TILE_SIZE);
	else
		return ((sideDistY - deltaDistY) * TILE_SIZE);
}

void	set_texture(t_data *data)
{
	data->texture_no.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->cub.textures.north, &data->texture_no.size.width,
			&data->texture_no.size.height);
	data->texture_no.addr = mlx_get_data_addr(data->texture_no.img_ptr,
			&data->texture_no.bits_per_pixel, &data->texture_no.line_length,
			&data->texture_no.endian);
	data->texture_so.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->cub.textures.south, &data->texture_so.size.width,
			&data->texture_so.size.height);
	data->texture_so.addr = mlx_get_data_addr(data->texture_so.img_ptr,
			&data->texture_so.bits_per_pixel, &data->texture_so.line_length,
			&data->texture_so.endian);
	data->texture_ea.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->cub.textures.east, &data->texture_ea.size.width,
			&data->texture_ea.size.height);
	data->texture_ea.addr = mlx_get_data_addr(data->texture_ea.img_ptr,
			&data->texture_ea.bits_per_pixel, &data->texture_ea.line_length,
			&data->texture_ea.endian);
	data->texture_we.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->cub.textures.west, &data->texture_we.size.width,
			&data->texture_we.size.height);
	data->texture_we.addr = mlx_get_data_addr(data->texture_we.img_ptr,
			&data->texture_we.bits_per_pixel, &data->texture_we.line_length,
			&data->texture_we.endian);
	set_color(data);
}
