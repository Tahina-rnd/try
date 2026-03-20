/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:24:08 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/13 18:24:55 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	add_map_line(t_map_data *data, char *line)
{
	char	**new_map;
	int		len;

	strip_newline(line);
	if (data->map_height >= data->map_capacity)
	{
		data->map_capacity *= 2;
		new_map = ft_realloc(data->map, sizeof(char *) * (data->map_capacity
					+ 1), sizeof(char *) * (data->map_height + 1));
		if (!new_map)
			return (ft_error("Malloc failed for map realloc"));
		data->map = new_map;
	}
	data->map[data->map_height] = ft_strdup(line);
	if (!data->map[data->map_height])
		return (ft_error("Malloc failed for map line strdup"));
	data->map_height++;
	data->map[data->map_height] = NULL;
	len = ft_strlen(line);
	if (len > data->map_width)
		data->map_width = len;
	return (0);
}

int	handle_identifier(char *line, t_map_data *data, int *in_map)
{
	int	ret;

	ret = parse_identifier(line, data);
	if (ret == 1)
	{
		*in_map = 1;
		strip_newline(line);
		if (init_map(data, line) != 0)
			return (-1);
	}
	else if (ret == -1)
		return (-1);
	return (0);
}

int	handle_map_line(char *line, t_map_data *data)
{
	if (is_empty_line(line))
		return (1);
	if (add_map_line(data, line) != 0)
		return (-1);
	return (0);
}
