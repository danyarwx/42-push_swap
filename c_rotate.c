/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:26:43 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/16 17:41:30 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !*stack || stack_len(*stack) < 2)
		return ;
	first = *stack;
	last = find_last(*stack);
	*stack = first->next; // remove first from head
	(*stack)->prev = NULL; // make second - head
	first->next = NULL; // make the first one last
	last->next = first; // connect to the last
	first->prev = last;
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}

