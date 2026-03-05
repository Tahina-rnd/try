/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:26:10 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/02 23:25:38 by tarandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "libftcore/libftcore.h"

typedef struct s_texture {
    char *north;
    char *south;
    char *west;
    char *east;
}               t_texture;

typedef struct s_rgb {
    int	r;
    int	g;
    int b;
}               t_rgb;

typedef struct s_map_data {
    t_texture	textures;
    t_rgb		floor_color;
    t_rgb		ceiling_color;
    char		**map;
	int			map_capacity;
    int			map_width;
    int			map_height;
    int			player_x;
    int			player_y;
    char		player_orientation;
}		  		t_map_data;

typedef struct s_point {
	int	x;
	int	y;
}	            t_point;

int     ft_error(char *error);
int 	map_format_checker(char *map);
int     parse_file(char *filename, t_map_data *data);
void	*ft_realloc(void *ptr, size_t new_size, size_t old_size);
void	free_map_data(t_map_data *data);


#endif