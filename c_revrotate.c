/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_revrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:45:19 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/26 19:40:56 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_stack **stack)
{
	t_stack *last;

	if (!stack || !*stack || stack_len(*stack) < 2)
		return ;
	last = find_last(*stack);

	last->prev->next = NULL; // disconnect last node
	last->prev = NULL; // make the prev of last null
	last->next = *stack; // connect the last node on top of the stack
	(*stack)->prev = last;
	*stack = last; // update the head node
}

void	rra(t_stack **a, bool print)
{
	revrotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print)
{
	revrotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	revrotate(a);
	revrotate(b);
	if (print)
		ft_printf("rrr\n");
}
