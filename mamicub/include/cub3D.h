/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:24:22 by maminran          #+#    #+#             */
/*   Updated: 2026/02/26 21:42:04 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3D_type.h"
# include "cub_keyconfig.h"
# include "cub_macros.h"
# include "cub_render.h"
# include "cub_window.h"
# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

void	create_image(t_data *data);
void	draw_minimap(t_data *data);
void	draw_texture(t_data *data, int x_start, int y_start);
void	get_texture(t_data *data);
void	pixel_put(t_data *data, int x, int y, int color);
int		update_position(t_data *data);
#endif
