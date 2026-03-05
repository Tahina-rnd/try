/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 23:33:12 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/05 21:49:42 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_identifiers_found(t_map_data *data)
{
	if (!data->textures.north || !data->textures.south
		|| !data->textures.west || !data->textures.east)
		return (0);
	if (data->floor_color.r == -1 || data->floor_color.g == -1
		|| data->floor_color.b == -1)
		return (0);
	if (data->ceiling_color.r == -1 || data->ceiling_color.g == -1
		|| data->ceiling_color.b == -1)
		return (0);
	return (1);
}

static int	space_line(char line)
{
	if (line == ' ' || line == '\t')
		return (1);
	return (0);
}

int	parse_identifier(char *line, t_map_data *data)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (ft_strncmp(line + i, "NO", 2) == 0 && space_line(line[i + 2]))
	{
		if (data->textures.north)
			return (ft_error("Duplicate NO identifier"));
		return (get_texture_path(&data->textures.north, line + i + 2));
	}
	if (ft_strncmp(line + i, "SO", 2) == 0 && space_line(line[i + 2]))
	{
		if (data->textures.south)
			return (ft_error("Duplicate SO identifier"));
		return (get_texture_path(&data->textures.south, line + i + 2));
	}
	if (ft_strncmp(line + i, "WE", 2) == 0 && space_line(line[i + 2]))
	{
		if (data->textures.west)
			return (ft_error("Duplicate WE identifier"));
		return (get_texture_path(&data->textures.west, line + i + 2));
	}
	if (ft_strncmp(line + i, "EA", 2) == 0 && space_line(line[i + 2]))
	{
		if (data->textures.east)
			return (ft_error("Duplicate EA identifier"));
		return (get_texture_path(&data->textures.east, line + i + 2));
	}
	if (ft_strncmp(line + i, "F", 1) == 0 && space_line(line[i + 1]))
	{
		if (data->floor_color.r != -1 || data->floor_color.g != -1
			|| data->floor_color.b != -1)
			return (ft_error("Duplicate F identifier"));
		return (get_color(&data->floor_color, line + i + 1));
	}
	if (ft_strncmp(line + i, "C", 1) == 0 && space_line(line[i + 1]))
	{
		if (data->ceiling_color.r != -1 || data->ceiling_color.g != -1
			|| data->ceiling_color.b != -1)
			return (ft_error("Duplicate C identifier"));
		return (get_color(&data->ceiling_color, line + i + 1));
	}
	if (line[i] == '1' || line[i] == '0' || is_player(line[i]))
		return (1);
	return (-1);
}
