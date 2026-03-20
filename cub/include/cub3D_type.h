/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:58:23 by maminran          #+#    #+#             */
/*   Updated: 2026/03/20 19:42:54 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TYPE_H
# define CUB3D_TYPE_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_texture
{
	char		*east;
	char		*north;
	char		*south;
	char		*west;
}				t_texture;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_map_data
{
	int			ceiling;
	t_rgb		ceiling_color;
	int			floor;
	t_rgb		floor_color;
	char		**map;
	int			map_capacity;
	int			map_height;
	int			map_width;
	double		player_x;
	double		player_y;
	char		player_orientation;
	t_texture	textures;
}				t_map_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_size
{
	int			height;
	int			width;
}				t_size;

typedef struct s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_move
{
	bool		back;
	bool		forward;
	bool		left;
	bool		right;
}				t_move;

typedef struct s_img
{
	char		*addr;
	int			bits_per_pixel;
	int			endian;
	void		*img_ptr;
	int			line_length;
	t_size		size;
}				t_img;

typedef enum e_side
{
	HORIZONTAL,
	VERTICAL
}				t_side;

typedef struct s_var
{
	int			draw_end;
	int			tex_y;
	int			tex_x;
	double		tex_pos;
	double		step;
	int			draw_start;
	int			line_h;
	int			start;
	double		fish_eye;

}				t_var;

typedef struct s_data
{
	double		angle;
	t_map_data	cub;
	t_img		img;
	t_move		look;
	char		**map;
	void		*mlx_ptr;
	t_move		move;
	t_pos		pos;
	t_side		side;
	t_size		screen;
	t_img		texture;
	t_img		texture_ea;
	t_img		texture_no;
	t_img		texture_so;
	t_img		texture_we;
	void		*win_ptr;
}				t_data;

#endif