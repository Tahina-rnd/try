/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manip_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 23:29:53 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/05 21:51:31 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_player(t_map_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (is_player(data->map[y][x]))
			{
				data->player_x = x;
				data->player_y = y;
				data->player_orientation = data->map[y][x];
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	normalize_map(t_map_data *data)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (i < data->map_height)
	{
		if (ft_strlen(data->map[i]) < (size_t)data->map_width)
		{
			new_line = malloc(sizeof(char) * (data->map_width + 1));
			if (!new_line)
				return ;
			ft_memcpy(new_line, data->map[i], ft_strlen(data->map[i]) + 1);
			j = ft_strlen(data->map[i]);
			while (j < data->map_width)
				new_line[j++] = ' ';
			new_line[data->map_width] = '\0';
			free(data->map[i]);
			data->map[i] = new_line;
		}
		i++;
	}
}

int	validate_map(t_map_data *data)
{
	int		i;
	char	**map_copy;

	normalize_map(data);
	i = 0;
	while (data->map[i] != NULL)
	{
		if (is_map_line(data->map[i]) == 0)
			return (ft_error("Invalid character in map"));
		i++;
	}
	if (check_player(data->map))
		return (ft_error("No player or multiple players"));
	if (find_player(data) != 0)
		return (ft_error("Player not found"));
	map_copy = duplicate_map(data->map, data->map_height);
	if (!map_copy)
		return (ft_error("Malloc failed for map copy"));
	if (!flood_fill(map_copy, data->player_x, data->player_y,
			data->map_width, data->map_height))
	{
		free_map_copy(map_copy, data->map_height);
		return (ft_error("Map is not closed"));
	}
	free_map_copy(map_copy, data->map_height);
	return (0);
}
