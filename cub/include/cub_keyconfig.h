/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keyconfig.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:05:35 by maminran          #+#    #+#             */
/*   Updated: 2026/03/18 08:58:13 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_KEYCONFIG_H
# define CUB_KEYCONFIG_H

int		key_pressed(int keypress, t_data *data);
int		key_release(int keycode, t_data *data);
void	move_player(t_data *data);
void	rotating(t_data *data);
#endif