/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:09:15 by maminran          #+#    #+#             */
/*   Updated: 2026/03/20 22:09:00 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_RENDER_H
# define CUB_RENDER_H

double			get_dist(t_data *data, double angle);
unsigned int	get_pixel_color(t_img *texture, int x, int y);
void			get_start_end(t_data *data, t_var *utils, t_img *tex);
t_img			*get_texture(t_data *data, double angle, int side);
int				part_start(t_data *data, t_img *tex, double angle);
void			put_texture_on_window(t_data *data, int x, t_var *utils,
					t_img *tex);
void			render_3d(t_data *data);
void			set_color(t_data *data);
double			ver_or_hor(t_data *data, double angle);

#endif