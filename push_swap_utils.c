/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 22:28:15 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/25 23:03:47 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return the node in b that was marked as the cheapest move.
t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

// Save each node's current index and whether it is in the top half.
void	set_pos(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (!stack)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}


// For each node in b, find the node in a it should be placed before.
// If there is no bigger value in a, the smallest node becomes the target.
void	set_targets(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		current_a = a;
		target_node = NULL;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

// Count how expensive it is to move each node from b back into a.
void	set_costs(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!b->above_median)
			b->push_price = len_b - b->current_position;
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - b->target_node->current_position;
		b = b->next;
	}
}

// Mark the node in b with the smallest total move cost.
void	mark_cheapest(t_stack *b)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (!b)
		return ;
	best_match_value = LONG_MAX;
	best_match_node = NULL;
	while (b)
	{
		b->cheapest = false;
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	if (best_match_node)
		best_match_node->cheapest = true;
}
