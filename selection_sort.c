/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sena <sena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:51:19 by sena              #+#    #+#             */
/*   Updated: 2023/04/24 14:58:29 by sena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_printarray(int *x, int size)
{
	int	i;

	i = size;
	ft_printf(DMG"--------------%c Stack-----------\n"RST , 's');
	while (--i >= 0)
		ft_printf(VIO"%c[%d]: %d\n"RST, 's', i, x[i]);
}

void	swap_index(int	*arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


/*

// 5 7 8 3
// index = 0
// min = 0


i = 0
j = 3
x = 3

return 0

---------
i = 1
j = 3
x = 3

return 3



--------
i = 2
j = 3
x = 3

return 3

-------
i = 3
j = 3


*/



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

// 5 7 8 3
// index = 0
// min = 0

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
