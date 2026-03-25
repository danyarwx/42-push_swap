/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:48:05 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/25 22:39:41 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 Refresh all metadata needed to choose the next move.
 */
void	prep_nodes(t_stack *a, t_stack *b)
{
	set_pos(a);
	set_pos(b);
	set_targets(a, b);
	set_costs(a, b);
	mark_cheapest(b);
}

/*
 Sort large stacks by keeping three numbers in a, then reinsert nodes from b
 one by one using the cheapest available move each time.
 */
void	push_swap(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a <= 5)
	{
		tiny_sort(a, b);
		return ;
	}
	while (len_a-- > 3)
		pb(b, a, true);
	sort_three(a);
	while (*b)
	{
		prep_nodes(*a, *b);
		push_best(a, b);
	}
	top_min(a);
}
