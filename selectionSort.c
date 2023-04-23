/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sena <sena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:51:19 by sena              #+#    #+#             */
/*   Updated: 2023/04/22 19:51:22 by sena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

// Yes it's recursive :)
void	selectin_sort(int *stack, int size, int index)
{
	int	min;

	if (size == index)
		return ;
	min = min_index(stack, index, size - 1);
	if (min != index)
		swap_index(stack, index, min);
	selectin_sort(stack, size, index + 1);
}
