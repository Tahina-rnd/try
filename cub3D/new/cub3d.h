/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarandri <tarandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:26:10 by tarandri          #+#    #+#             */
/*   Updated: 2026/03/05 21:53:49 by tarandri         ###   ########.fr       */
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

/* ── Structures ─────────────────────────────────────────────────────────── */

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_texture;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_map_data
{
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
}	t_map_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/* ── ft_error.c ─────────────────────────────────────────────────────────── */

int		ft_error(char *msg);

/* ── ft_realloc.c ───────────────────────────────────────────────────────── */

void	*ft_realloc(void *ptr, size_t new_size, size_t old_size);

/* ── map_format_checker.c ───────────────────────────────────────────────── */

int		map_format_checker(char *map);

/* ── parsing.c ──────────────────────────────────────────────────────────── */

int		parse_file(char *filename, t_map_data *data);

/* ── parsing_utils.c ────────────────────────────────────────────────────── */

int		is_empty_line(char *line);
int		is_player(char c);
int		check_player(char **map);

/* ── parse_identifier.c ─────────────────────────────────────────────────── */

int		all_identifiers_found(t_map_data *data);
int		parse_identifier(char *line, t_map_data *data);

/* ── get_texture_path.c ─────────────────────────────────────────────────── */

void	strip_newline(char *s);
int		get_texture_path(char **texture_dest, char *line);

/* ── get_color_path.c ───────────────────────────────────────────────────── */

int		get_color(t_rgb *color, char *line);

/* ── map_manip.c ────────────────────────────────────────────────────────── */

int		is_map_line(char *line);
char	**duplicate_map(char **original, int height);
void	free_map_copy(char **map_copy, int height);

/* ── map_manip_2.c ──────────────────────────────────────────────────────── */

int		find_player(t_map_data *data);
void	normalize_map(t_map_data *data);
int		validate_map(t_map_data *data);

/* ── flood_fil.c ────────────────────────────────────────────────────────── */

int		flood_fill(char **map, int start_x, int start_y,
			int width, int height);

/* ── free_map.c ─────────────────────────────────────────────────────────── */

void	free_map_data(t_map_data *data);

#endif