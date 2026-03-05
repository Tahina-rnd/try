/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:58:23 by maminran          #+#    #+#             */
/*   Updated: 2026/02/27 00:45:34 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TYPE_H
# define CUB3D_TYPE_H

# include <stdbool.h>

typedef struct s_size
{
	int		height;
	int		width;
}			t_size;

typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_move
{
	bool	back;
	bool	forward;
	bool	left;
	bool	right;
}			t_move;

typedef struct s_img
{
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	void	*img_ptr;
	int		line_length;
	t_size	size;
}			t_img;

typedef struct s_data
{
	double	angle;
	t_img	img;
	t_move	look;
	char	**map;
	void	*mlx_ptr;
	t_move	move;
	t_pos	pos;
	t_size	screen;
	t_img	texture;
	void	*win_ptr;
}			t_data;

#endif