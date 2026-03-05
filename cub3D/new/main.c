/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:30:16 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/05 21:43:37 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_map_data	data;

	if (ac != 2)
		return (ft_error("Usage: ./cub3D map.cub"));
	if (map_format_checker(av[1]))
		return (1);
	if (parse_file(av[1], &data))
		return (1);
	free_map_data(&data);
	return (0);
}
