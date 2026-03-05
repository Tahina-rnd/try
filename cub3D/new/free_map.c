/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:49:31 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/02 22:53:48 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_map_data(t_map_data *data)
{
    int i;

    if (data->textures.north)
        free(data->textures.north);
    if (data->textures.south)
        free(data->textures.south);
    if (data->textures.west)
        free(data->textures.west);
    if (data->textures.east)
        free(data->textures.east);    
    if (data->map)
    {
        i = 0;
        while (i < data->map_height)
        {
            if (data->map[i])
                free(data->map[i]);
            i++;
        }
        free(data->map);
    }
}
