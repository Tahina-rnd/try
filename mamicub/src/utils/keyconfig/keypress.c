/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:13:21 by maminran          #+#    #+#             */
/*   Updated: 2026/03/01 20:36:03 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_pressed(int keypress, t_data *data)
{
	if (keypress == XK_w)
		data->move.forward = true;
	else if (keypress == XK_s)
		data->move.back = true;
	else if (keypress == XK_a)
		data->move.left = true;
	else if (keypress == XK_d)
		data->move.right = true;
	else if (keypress == XK_Left)
		data->look.left = true;
	else if (keypress == XK_Right)
		data->look.right = true;
	else if (keypress == XK_Escape)
		close_window(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->move.forward = false;
	if (keycode == XK_a)
		data->move.left = false;
	if (keycode == XK_d)
		data->move.right = false;
	if (keycode == XK_s)
		data->move.back = false;
	if (keycode == XK_Left)
		data->look.left = false;
	if (keycode == XK_Right)
		data->look.right = false;
	return (0);
}

int	update_position(t_data *data)
{
	ft_bzero(data->img.addr, data->img.line_length * data->screen.height);
	rotating(data);
	walk(data);
	laterale(data);
	render_3d(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
	return (0);
}
