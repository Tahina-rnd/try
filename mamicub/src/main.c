/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:46:07 by maminran          #+#    #+#             */
/*   Updated: 2026/03/01 19:51:41 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*map[] = {"111111111", "100011001", "101101011", "100000001",
		"101001011", "101101001", "100000011", "100101001", "101010101",
		"100010001", "111111111", NULL};

void	init_data(t_data *data)
{
	int	i;

	ft_bzero(data, sizeof(t_data));
	data->map = malloc(sizeof(char *) * 20);
	i = 0;
	while (map[i])
	{
		data->map[i] = ft_strdup(map[i]);
		i++;
	}
	data->map[i] = NULL;
	data->pos.x = 70.0;
	data->pos.y = 70.0;
}

int	main(void)
{
	t_data	data;

	init_data(&data);
	open_window(&data);
	create_image(&data);
	get_texture(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_pressed, &data);
	mlx_hook(data.win_ptr, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx_ptr, update_position, &data);
	mlx_hook(data.win_ptr, 17, 0, quit_click, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
