/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:46:19 by maminran          #+#    #+#             */
/*   Updated: 2026/02/25 12:13:53 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	create_image(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->screen.width,
			data->screen.height);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
}

void	open_window(t_data *data)
{
	int	width;
	int	height;

	data->mlx_ptr = mlx_init();
	mlx_get_screen_size(data->mlx_ptr, &width, &height);
	data->screen.width = width * 0.8;
	data->screen.height = height * 0.8;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen.width,
			data->screen.height, "cub3D");
}
