/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:38:11 by zdogan            #+#    #+#             */
/*   Updated: 2022/07/26 16:09:57 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
}