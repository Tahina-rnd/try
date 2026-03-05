/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:09:15 by maminran          #+#    #+#             */
/*   Updated: 2026/02/27 00:58:25 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_RENDER_H
# define CUB_RENDER_H

void			draw_v_line(t_data *data, int x, int line_h, int tex_x);
void			render_3d(t_data *data);
unsigned int	get_pixel_color(t_data *data, int x, int y);
double			get_dist(t_data *data, double angle);

#endif