/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sena <sena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:51:09 by sena              #+#    #+#             */
/*   Updated: 2023/04/22 19:51:12 by sena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push.h"

int	radix_sort_check(t_swap *index)
{
	int	i;

	i = 0;
	while (i < index->len - 1)
	{
		if (index->stack[i] > index->stack[i + 1])
			++i;
		else
			return (0);
	}
	return (1);
}

void	radix_a(t_swap *a, t_swap *b, int i)
{
	if (radix_sort_check(a) == 0)
	{
		if (((a->stack[a->len - 1] >> i) & 1) == 0)
			push(a, b);
		else
			rotate(a, 1);
	}
}

int	get_max_bits(t_swap *index)
{
	int	bit_size;
	int	size;

	bit_size = 0;
	size = index->len;
	while (size > 1)
	{
		bit_size++;
		size /= 2;
	}
	return (bit_size);
}

void	radix_sort(t_swap *a, t_swap *b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	max_bits = get_max_bits(a);
	while (i <= max_bits)
	{
		ft_printstack(a);
		j = 0;
		size = a->len;
		while (j < size)
		{
			radix_a(a, b, i);
			ft_printstack(a);
			ft_printstack(b);
			j++;
		}
		i++;
		while (b->len)
			push(b, a);
	}
}
