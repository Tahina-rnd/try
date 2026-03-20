/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:46:07 by maminran          #+#    #+#             */
/*   Updated: 2026/03/19 01:40:26 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_color(t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = data->cub.ceiling_color.r;
	g = data->cub.ceiling_color.g;
	b = data->cub.ceiling_color.b;
	data->cub.ceiling = (r << 16) | (g << 8) | b;
	r = data->cub.floor_color.r;
	g = data->cub.floor_color.g;
	b = data->cub.floor_color.b;
	data->cub.floor = (r << 16) | (g << 8) | b;
}

void	get_pos(t_data *data)
{
	data->cub.player_x *= TILE_SIZE;
	data->cub.player_x += TILE_SIZE / 2;
	data->cub.player_y *= TILE_SIZE;
	data->cub.player_y += TILE_SIZE / 2;
	if (data->cub.player_orientation == 'N')
		data->angle = 3 * M_PI / 2;
	if (data->cub.player_orientation == 'S')
		data->angle = M_PI / 2;
	if (data->cub.player_orientation == 'E')
		data->angle = 0;
	if (data->cub.player_orientation == 'W')
		data->angle = M_PI;
}

int	main(int ac, char **av)
{
	t_data		data;
	t_map_data	data_map;

	if (ac != 2)
		return (ft_error("Usage: ./cub3D map.cub"));
	if (map_format_checker(av[1]))
		return (1);
	if (parse_file(av[1], &data_map))
		return (free_map_data(&data_map), 1);
	ft_bzero(&data, sizeof(t_data));
	data.cub = data_map;
	get_pos(&data);
	open_window(&data);
	create_image(&data);
	set_texture(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_pressed, &data);
	mlx_hook(data.win_ptr, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx_ptr, update_position, &data);
	mlx_hook(data.win_ptr, 17, 0, quit_click, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
