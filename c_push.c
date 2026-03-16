/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:00:16 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/16 17:27:16 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack *node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = node->next; // detach the node from the head of the A stack
	if (*src)
		(*src)->prev = NULL; // make the second node of A the head
	node->prev = NULL; // make new node the head
	node->next = *dest;
	if (*dest)
		(*dest)->prev = node; // attach it to stack B
	*dest = node; // update the head
}

// Confusing order might fix it later
void	pa(t_stack **a, t_stack **b, bool print) // push to a from b
{
	push(b, a); // push from b to a
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, bool print) // push to b from a
{
	push(a, b); // push from a to b
	if (print)
		ft_printf("pb\n");
}
