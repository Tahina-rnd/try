/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:07:28 by maminran          #+#    #+#             */
/*   Updated: 2025/06/19 23:40:15 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../ft_string/ft_string.h"
# include <stdarg.h>

int	get_format(char format, va_list args_write);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_put_hex(char x, unsigned int n);
int	ft_printf(const char *format, ...);
int	ft_put_pointer_address(void *ptr);
int	ft_putpos_nbr(unsigned int n);

#endif