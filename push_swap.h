/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:20:33 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/25 22:42:28 by dzhukov          ###   ########.fr       */
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
	int				value;
	int				index;
	int				current_position;
	int				push_price;
	bool			above_median;
	bool			cheapest;

	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		main(int argc, char **argv);

// Parsing
long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
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
int		stack_sorted(t_stack *stack);
t_stack	*find_last(t_stack *head);
t_stack	*find_min(t_stack *stack);

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

// Sorting
void	tiny_sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	push_swap(t_stack **a, t_stack **b);

// Push_Swap
void	prep_nodes(t_stack *a, t_stack *b);

t_stack	*get_cheapest(t_stack *stack);
void	set_pos(t_stack *stack);
void	set_targets(t_stack *a, t_stack *b);
void	set_costs(t_stack *a, t_stack *b);
void	mark_cheapest(t_stack *b);

void	rot_both(t_stack **a, t_stack **b, t_stack *cheap);
void	rev_rot_both(t_stack **a, t_stack **b, t_stack *cheap);
void	finish_rot(t_stack **stack, t_stack *top_node, char name);
void	push_best(t_stack **a, t_stack **b);
void	top_min(t_stack **a);



#endif
