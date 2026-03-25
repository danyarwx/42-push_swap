/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:56:59 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/25 19:07:43 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*min;
	int		min_pos;
	int		size;

	min = find_min(*a);
	current = *a;
	min_pos = 0;
	size = stack_len(*a);
	while (current != min)
	{
		min_pos++;
		current = current->next;
	}
	if (min_pos <= size / 2)
	{
		while (*a != min)
			ra(a, true);
	}
	else
	{
		while (*a != min)
			rra(a, true);
	}
	pb(b, a, true);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;

	if (first > second && second > third)
	{
		sa(a, true);
		rra(a, true);
	}
	else if (first > second && first > third)
		ra(a, true);
	else if (second > third && first < third)
	{
		sa(a, true);
		ra(a, true);
	}
	else if (second > first && second > third)
		rra(a, true);
	else if (first > second)
		sa(a, true);
}

void	tiny_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_len(*a);
	if (size < 2)
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, true);
		return ;
	}
	while (size-- > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b, true);
}
