/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:21:16 by maminran          #+#    #+#             */
/*   Updated: 2025/06/19 23:47:25 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int		i;
	int		len;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	ft_putpos_nbr(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n > 9)
	{
		count += ft_putpos_nbr(n / 10);
		count += ft_putpos_nbr(n % 10);
	}
	else
	{
		c = n + '0';
		count += ft_putchar(c);
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int		count;
	char	*str;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	str = ft_itoa(n);
	if (!str)
		return (-1);
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	free(str);
	return (count);
}
