/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:13:52 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/25 22:34:14 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		make_stack(&a, argv, true);
	}
	else
		make_stack(&a, argv + 1, false);
	if (!stack_sorted(a))
	{
		if (stack_len(a) <= 5)
			tiny_sort(&a, &b);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (0);
}
