/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:20:33 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/16 00:05:51 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/include/ft_printf.h"
# include <limits.h>


typedef struct s_stack
{
	int value;
	int index;

	struct s_stack *target_node;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

int	main(int argc, char **argv);



#endif
