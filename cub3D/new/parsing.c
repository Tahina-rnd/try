/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:31:24 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/05 21:45:27 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	add_map_line(t_map_data *data, char *line)
{
	char	**new_map;
	int		len;

	strip_newline(line);
	if (data->map_height >= data->map_capacity)
	{
		data->map_capacity *= 2;
		new_map = ft_realloc(data->map,
				sizeof(char *) * (data->map_capacity + 1),
				sizeof(char *) * (data->map_height + 1));
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

static void	init_data(t_map_data *data)
{
	ft_memset(data, 0, sizeof(t_map_data));
	data->floor_color.r = -1;
	data->floor_color.g = -1;
	data->floor_color.b = -1;
	data->ceiling_color.r = -1;
	data->ceiling_color.g = -1;
	data->ceiling_color.b = -1;
}

static int	init_map(t_map_data *data, char *line)
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

static int	handle_identifier(char *line, t_map_data *data, int *in_map)
{
	int	ret;

	ret = 0;
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

static int	handle_map_line(char *line, t_map_data *data)
{
	if (is_empty_line(line))
	{
		free(line);
		return (1);
	}
	if (add_map_line(data, line) != 0)
	{
		free(line);
		return (-1);
	}
	return (0);
}

static int	process_line(char *line, t_map_data *data, int *in_map)
{
	int	ret;

	if (!*in_map && is_empty_line(line))
		return (2);
	if (!*in_map)
	{
		ret = handle_identifier(line, data, in_map);
		if (ret == -1)
		{
			free(line);
			return (ft_error("Invalid identifier"));
		}
		if (*in_map)
			free(line);
		return (0);
	}
	ret = handle_map_line(line, data);
	if (ret == -1)
		return (1);
	if (ret == 1)
		return (3);
	return (0);
}

static int	read_loop(int fd, t_map_data *data)
{
	char	*line;
	int		in_map;
	int		ret;

	in_map = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		ret = process_line(line, data, &in_map);
		if (ret == 2)
		{
			free(line);
			continue ;
		}
		if (ret == 1 || ret == 3)
		{
			free(line);
			break ;
		}
		if (ret != 0)
			return (ret);
		free(line);
	}
	if (ret == 1)
		return (1);
	return (0);
}

int	parse_file(char *filename, t_map_data *data)
{
	int	fd;
	int	ret;

	init_data(data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_error("Cannot open file"));
	ret = read_loop(fd, data);
	close(fd);
	if (ret != 0)
		return (ret);
	if (!all_identifiers_found(data))
		return (ft_error("Missing identifiers"));
	if (validate_map(data) != 0)
		return (1);
	return (0);
}
