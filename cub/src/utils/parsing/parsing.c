/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:31:24 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/15 13:32:08 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	process_line(char *line, t_map_data *data, int *in_map)
{
	int	ret;

	if (!*in_map && is_empty_line(line))
		return (2);
	if (!*in_map)
	{
		ret = handle_identifier(line, data, in_map);
		if (ret == -1)
			return (ft_error("Invalid identifier"));
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
	ret = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ret = process_line(line, data, &in_map);
		ret = 0; // lasa misy boucle infini ret=2, dia nataoko = 0 aloha ito
		free(line);
		if (ret == 2)
			continue ;
		if (ret == 1 || ret == 3)
			break ;
		if (ret != 0)
			return (ret);
		line = get_next_line(fd);
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
