/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sena <sena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 03:47:21 by zdogan            #+#    #+#             */
/*   Updated: 2023/04/23 15:11:23 by sena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				neg;
	long long int	res;

	neg = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' \
			|| *str == '\f' || *str == '\r')
			str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + *str - 48;
		str++;
	}
	if (res * neg > 2147483647 || res * neg < -2147483648)
		return (0);
	return ((int)(res * neg));
}


// int	ft_atoi(const char *str)
// {
// 	int				neg;
// 	long long int	res;

// 	neg = 1;
// 	res = 0;
// 	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' \
// 			|| *str == '\f' || *str == '\r')
// 			str++;
// 	if (*str == '-' || *str == '+')
// 	{
// 		if (*str == '-')
// 			neg = -1;
// 		str++;
// 	}
// 	while (*str && ft_isdigit(*str))
// 	{
// 		res = res * 10 + *str - 48;
// 		if (res * neg > 2147483647)
// 			return (-1);
// 		if (res * neg < -2147483648)
// 			return (0);
// 		str++;
// 	}
// 	return ((int)(res * neg));
// }

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - 48) * sign;
		i++;
	}
	return (number);
}