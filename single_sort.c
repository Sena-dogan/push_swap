/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:51:29 by sena              #+#    #+#             */
/*   Updated: 2023/04/27 16:08:08 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	three_sort(t_swap *a)
{
	if (a->stack[2] == 0 && a->stack[1] == 2)
	{
		r_rotate(a, 1);
		swap(a, 1);
	}
	else if (a->stack[2] == 1 && a->stack[1] == 0)
		swap(a, 1);
	else if (a->stack[2] == 1 && a->stack[1] == 2)
		r_rotate(a, 1);
	else if (a->stack[2] == 2 && a->stack[1] == 0)
		rotate(a, 1);
	else if (a->stack[2] == 2 && a->stack[1] == 1)
	{
		swap(a, 1);
		r_rotate(a, 1);
	}
}

void	four_sort(t_swap *a, t_swap *b)
{
	if (a->stack[3] == 3 || a->stack[2] == 3)
	{
		if (a->stack[2] == 3)
			rotate(a, 1);
		push(a, b);
		three_sort(a);
	}
	else
	{
		if (a->stack[1] == 3)
			r_rotate(a, 1);
		r_rotate(a, 1);
		push(a, b);
		three_sort(a);
	}
	push(b, a);
	rotate(a, 1);
}

void	five_sort(t_swap *a)
{
	if (a->stack[4] == 4 || a->stack[3] == 4)
	{
		if (a->stack[1] == 4)
			rotate(a, 1);
		if (a->stack[a->len - 1] != 4)
			rotate(a, 1);
	}
	else if (a->stack[2] == 4 || a->stack[1] == 4 || a->stack[0] == 4)
	{
		if (a->stack[2] == 4)
		{
			rotate(a, 1);
			rotate(a, 1);
		}
		else
		{
			if (a->stack[0] != 4)
				r_rotate(a, 1);
			r_rotate(a, 1);
			if (a->stack[0] == 4)
				r_rotate(a, 1);
		}
	}
}

void	little_sort(t_swap *a, t_swap *b)
{
	if (a->len == 2)
		rotate(a, 1);
	else if (a->len == 3)
		three_sort(a);
	else if (a->len == 4)
		four_sort(a, b);
	else if (a->len == 5)
	{
		five_sort(a);
		push(a, b);
		four_sort(a, b);
		push(b, a);
		rotate(a, 1);
	}
}
