/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sena <sena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:51:52 by sena              #+#    #+#             */
/*   Updated: 2023/04/23 22:33:19 by sena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push.h"

void	ft_printstack(t_swap *x)
{
	int	i;

	i = x->len;
	ft_printf(DMG"--------------%c Stack-----------\n"RST , x->id);
	while (--i >= 0)
		ft_printf(VIO"%c[%d]: %d\n"RST, x->id, i, x->stack[i]);
}

int	find_index(int *arr, int x, int size)
{
	int	i;

	i = 0;
	while (i < size -1 && arr[i] != x)
		i++;
	return (i);
}

void	to_index(t_swap *a, t_swap *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->len)
	{
		j = find_index(c->stack, a->stack[i], a->len);
		a->stack[i] = j;
		i++;
	}
}

void	rr(t_swap *a, t_swap *b, int flag)
{
	rotate(a, 0);
	rotate(b, 0);
	if (flag)
		ft_printf(YEL"rr\n"RST);
}

void	rrr(t_swap *a, t_swap *b)
{
	r_rotate(a, 0);
	r_rotate(b, 0);
	ft_printf(YEL"rrr"RST);
}
