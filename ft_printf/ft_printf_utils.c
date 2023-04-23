/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sena <sena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:36:37 by zdogan            #+#    #+#             */
/*   Updated: 2023/04/23 15:32:01 by sena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str, int flag)
{
	char	*mem;
	int		fd;

	fd = flag;
	if (!str)
		return (ft_putstr("(null)", 1));
	mem = str;
	while (*str)
		write(fd, str++, 1);
	return (str - mem);
}

int	ft_hex(unsigned long long arg, char c)
{
	int		x;
	char	*base;

	x = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (arg >= 16)
		x += ft_hex(arg / 16, c);
	x += write(1, &base[arg % 16], 1);
	return (x);
}

int	ft_putint(long arg, char *base)
{
	int	x;

	x = 0;
	if (arg < 0)
	{
		arg = -arg;
		write(1, "-", 1);
		x = 1;
	}
	if (arg >= 10)
		x += ft_putint(arg / 10, base);
	x += write(1, &base[arg % 10], 1);
	return (x);
}

int	ft_putunsigned(unsigned long arg, char *base)
{
	int	x;

	x = 0;
	if (arg >= 10)
		x += ft_putint(arg / 10, base);
	x += write(1, &base[arg % 10], 1);
	return (x);
}
