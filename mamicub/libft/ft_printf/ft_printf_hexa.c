/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminran <maminran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:36:49 by maminran          #+#    #+#             */
/*   Updated: 2025/06/19 23:43:28 by maminran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(char x, unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_put_hex(x, n / 16);
	if (n % 16 < 10)
		c = (n % 16) + '0';
	else if (x == 'x')
		c = (n % 16) - 10 + 'a';
	else
		c = (n % 16) - 10 + 'A';
	write(1, &c, 1);
	count++;
	return (count);
}

static int	ft_address_helper(unsigned long n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_address_helper(n / 16);
	if (n % 16 < 10)
		c = (n % 16) + '0';
	else
		c = (n % 16) - 10 + 'a';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_put_pointer_address(void *ptr)
{
	unsigned long	address;
	int				count;

	count = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	count += ft_putchar('0');
	count += ft_putchar('x');
	count += ft_address_helper(address);
	return (count);
}
