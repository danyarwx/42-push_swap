/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:13:52 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/16 00:01:28 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	make_stack(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			swap(&a, false);
		else if (stack_len == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);



	// char	**array=NULL;

	// if (argc == 1)
	// 	return 1;

	// array = ft_split(argv[1], ' ');

	// int i = 0;
	// int j = 0;
	// while (i < 5)
	// {
	// 	ft_printf("%s\n", array[i]);
	// 	i++;
	// }
	// ft_free(array, 5);

	return (0);
}

