/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:51:01 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/08 14:58:19 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_format_checker(char *map)
{
	int	len;

	if (!map)
		return (ft_error("Map pointer is NULL"));
	len = ft_strlen(map);
	if (len < 5)
		return (ft_error("Filename too short for .cub extension"));
	if (ft_strncmp(map + len - 4, ".cub", 4) != 0)
		return (ft_error("File extension is not .cub"));
	if (map[len - 5] == '.' || map[len - 5] == '/')
		return (ft_error("Invalid filename (hidden file or path issue)"));
	return (0);
}
