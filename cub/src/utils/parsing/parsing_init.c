/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:12:03 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/13 18:12:51 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_map_data *data)
{
	ft_memset(data, 0, sizeof(t_map_data));
	data->floor_color.r = -1;
	data->floor_color.g = -1;
	data->floor_color.b = -1;
	data->ceiling_color.r = -1;
	data->ceiling_color.g = -1;
	data->ceiling_color.b = -1;
}

int	init_map(t_map_data *data, char *line)
{
	data->map_capacity = 8;
	data->map = malloc(sizeof(char *) * (data->map_capacity + 1));
	if (!data->map)
		return (ft_error("Malloc failed for map"));
	data->map[0] = ft_strdup(line);
	if (!data->map[0])
	{
		free(data->map);
		return (ft_error("Malloc failed for first map line"));
	}
	data->map[1] = NULL;
	data->map_height = 1;
	data->map_width = ft_strlen(line);
	return (0);
}
