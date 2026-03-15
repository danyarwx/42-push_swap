/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:20:33 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/16 01:07:24 by dzhukov          ###   ########.fr       */
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

int	main(int argc, char **argv);

// Parsing
long	ft_atol(const char *str);
void make_stack(t_stack **a, char **argv, bool fake);
void add_node(t_stack **stack, int num);

// Errors
void fail_free(t_stack **a, char **argv, bool fake);
void	free_arr(char **argv);
void	free_stack(t_stack **stack);
int	syntax_fail(char *str);
int	rep_fail(t_stack *a, int num);

#endif
