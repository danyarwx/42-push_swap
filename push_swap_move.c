/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 22:28:22 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/25 23:00:35 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate both stacks together while both needed nodes are below the top.

void	rot_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap->target_node && *b != cheap)
		rr(a, b, true);
	set_pos(*a);
	set_pos(*b);
}

// Reverse rotate both stacks together when both nodes are in the bottom half.

void	rev_rot_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap->target_node && *b != cheap)
		rrr(a, b, true);
	set_pos(*a);
	set_pos(*b);
}

// Finish rotating one stack until the wanted node reaches the top.

void	finish_rot(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

// Bring the cheapest node in b and its target in a to the top, then push it.

void	push_best(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheapest(*b);
	if (!cheap)
		return ;
	if (cheap->above_median && cheap->target_node->above_median)
		rot_both(a, b, cheap);
	else if (!cheap->above_median && !cheap->target_node->above_median)
		rev_rot_both(a, b, cheap);
	finish_rot(b, cheap, 'b');
	finish_rot(a, cheap->target_node, 'a');
	pa(a, b, true);
}

// Rotate a until the smallest value becomes the top node.

void	top_min(t_stack **a)
{
	t_stack	*smallest;

	set_pos(*a);
	smallest = find_min(*a);
	if (!smallest)
		return ;
	if (smallest->above_median)
	{
		while (*a != smallest)
			ra(a, true);
	}
	else
	{
		while (*a != smallest)
			rra(a, true);
	}
}
