/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 19:50:39 by sena              #+#    #+#             */
/*   Updated: 2023/04/27 16:36:49 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_getlen(char **argv)
{
	int	i;

	i = 0;
	while (*(++argv))
		i++;
	return (i);
}

char	**argv_init(char **argv, int argc)
{
	char	*buffer;
	char	*tmp;
	int		i;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		buffer = ft_strdup("");
		while (i < argc)
		{
			tmp = buffer;
			buffer = ft_strjoin(buffer, argv[i]);
			free(tmp);
			tmp = buffer;
			buffer = ft_strjoin(buffer, " ");
			free(tmp);
			++i;
		}
		argv = ft_split(buffer, ' ');
	}
	if (!argv || !argv[0])
		exit(0);
	return (argv);
}

void	start_struct(t_swap *a, t_swap *b, t_swap *c, char **argv)
{
	a->len = ft_getlen(argv);
	c->len = a->len;
	a->id = 'a';
	b->id = 'b';
	c->id = 'c';
	a->stack = ft_calloc(sizeof(int), a->len);
	b->stack = ft_calloc(sizeof(int), a->len);
	c->stack = ft_calloc(sizeof(int), a->len);
	ft_getarg(argv, a, b, c);
	if (!sort_check(a->stack, a->len))
	{
		destroy(a, b, c);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_swap	*a;
	t_swap	*b;
	t_swap	*c;

	if (ft_argcontrol(argc, argv) && argv[1] && *argv[1] && argc >= 2)
	{
		a = ft_calloc(sizeof(t_swap), 1);
		b = ft_calloc(sizeof(t_swap), 1);
		c = ft_calloc(sizeof(t_swap), 1);
		argv = argv_init(argv, argc);
		start_struct(a, b, c, argv);
		selection_sort(c->stack, c->len, 0);
		to_index(a, c);
		if (a->len < 6)
			little_sort(a, b);
		else
			radix_sort(a, b);
		if (argc == 2)
			free_argv(argv);
		destroy(a, b, c);
	}
	else if (argv[1] && *(argv[1]) && argc >= 2)
		ft_printf("%e", "Error\n");
	return (0);
}
