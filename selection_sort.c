/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:51:19 by sena              #+#    #+#             */
/*   Updated: 2023/04/27 17:04:22 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_printarray(int *x, int size)
{
	int	i;

	i = size;
	ft_printf("--------------S Stack-----------\n");
	while (--i >= 0)
		ft_printf("%c[%d]: %d\n", 's', i, x[i]);
}

void	swap_index(int	*arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int	min_index(int *arr, int i, int j)
{
	int	x;

	if (i == j)
		return (i);
	x = min_index(arr, i + 1, j);
	if (arr[i] < arr[x])
		return (i);
	return (x);
}

void	selection_sort(int *stack, int size, int index)
{
	int	min;

	if (size == index)
		return ;
	min = min_index(stack, index, size - 1);
	if (min != index)
		swap_index(stack, index, min);
	selection_sort(stack, size, index + 1);
}
