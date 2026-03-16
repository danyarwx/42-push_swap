/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:20:33 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/16 18:07:31 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/include/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack
{
	int value;
	int index;

	struct s_stack *target_node;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

int		main(int argc, char **argv);

// Parsing
long	ft_atol(const char *str);
void	make_stack(t_stack **a, char **argv, bool fake);
void 	add_node(t_stack **stack, int num);

// Errors
void	fail_free(t_stack **a, char **argv, bool fake);
void	free_arr(char **argv);
void	free_stack(t_stack **stack);
int		syntax_fail(char *str);
int		rep_fail(t_stack *a, int num);

// Utils
int		stack_len(t_stack *stack);
t_stack	*find_last(t_stack *head);

// Commands
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);

void	swap(t_stack **stack);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

void	rotate(t_stack **stack);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);

void	revrotate(t_stack **stack);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);


#endif
