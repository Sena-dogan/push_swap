/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sena <sena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:50:59 by sena              #+#    #+#             */
/*   Updated: 2023/04/22 19:51:02 by sena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_H
# define PUSH_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct s_swap
{
	int		*stack;
	int		len;
	char	id;
}t_swap;

void	ft_printstack(t_swap *s);
void	push(t_swap *a, t_swap *b);
void	ft_getarg(char **argv, t_swap *a, t_swap *b, t_swap *c);
void	free_argv(char **argv);
int		ft_argcontrol(int argc, char **argv);
void	ss(t_swap *a, t_swap *b);
void	rotate(t_swap *x, int flag);
void	r_rotate(t_swap *x, int flag);
void	rrr(t_swap *a, t_swap *b);
void	rr(t_swap *a, t_swap *b, int flag);
void	selectin_sort(int *stack, int size, int index);
void	to_index(t_swap *a, t_swap *c);
void	radix_sort(t_swap *a, t_swap *b);
int		sort_check(int *stack, int len);
void	destroy(t_swap *a, t_swap *b, t_swap *c);
void	little_sort(t_swap *a, t_swap *b);
void	swap(t_swap *x, int flag);
int		repeat_check(int *stack, int len);

#endif