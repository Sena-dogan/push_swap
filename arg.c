/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:49:45 by sena              #+#    #+#             */
/*   Updated: 2023/04/27 17:02:49 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	destroy(t_swap *a, t_swap *b, t_swap *c)
{
	free(a->stack);
	free(b->stack);
	free(c->stack);
	free(a);
	free(b);
	free(c);
}

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

int	ft_argcontrol(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i] && *argv[i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == ' ')
				continue ;
			if (!ft_isdigit(argv[i][j])
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (0);
		}
	}
	return (1);
}

void	ft_getarg(char **argv, t_swap *a, t_swap *b, t_swap *c)
{
	int	i;
	int	len;

	len = a->len;
	i = 0;
	while (i <= a->len)
	{
		if (ft_atoi(argv[len]) == 0 && argv[len][0] != '0')
		{
			ft_printf("%e", "Error\n");
			destroy(a, b, c);
			exit(0);
		}
		a->stack[i++] = ft_atoi(argv[len--]);
	}
	i = -1;
	len = a->len;
	while (argv[++i] && argv[len])
		c->stack[i] = ft_atoi(argv[len--]);
	a->len++;
	c->len++;
}

int	sort_check(int *stack, int len)
{
	int	i;
	int	x;

	i = -1;
	while (++i <= len)
	{
		x = i;
		while (++x < len)
		{
			if (stack[i] == stack[x])
			{
				ft_printf("%e", "Error\n");
				return (0);
			}
		}
	}
	i = 0;
	while (i + 1 < len)
	{
		if (stack[i] > stack[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}
