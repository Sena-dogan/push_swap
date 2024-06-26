/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:50:28 by sena              #+#    #+#             */
/*   Updated: 2023/04/27 16:14:25 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap(t_swap *x, int flag)
{
	int	temp;

	temp = x->stack[x->len - 2];
	x->stack[x->len - 2] = x->stack[x->len - 1];
	x->stack[x->len - 1] = temp;
	if (flag)
		ft_printf("s%c\n", x->id);
}

void	push(t_swap *a, t_swap *b)
{
	if (a->len > 0)
	{
		b->len++;
		b->stack[b->len - 1] = a->stack[a->len - 1];
		a->len--;
		ft_printf("p%c\n", b->id);
	}
}

void	ss(t_swap *a, t_swap *b)
{
	swap(a, 0);
	swap(b, 0);
}

void	rotate(t_swap *x, int flag)
{
	int	temp;

	temp = x->stack[x->len - 1];
	ft_memmove(&x->stack[1], &x->stack[0], (x->len - 1) * 4);
	x->stack[0] = temp;
	if (flag)
		ft_printf("r%c\n", x->id);
}

void	r_rotate(t_swap *x, int flag)
{
	int	temp;

	temp = x->stack[0];
	ft_memmove(&x->stack[0], &x->stack[1], (x->len - 1) * 4);
	x->stack[x->len - 1] = temp;
	if (flag)
		ft_printf("rr%c\n", x->id);
}
