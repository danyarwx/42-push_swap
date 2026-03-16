/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:32:47 by dzhukov           #+#    #+#             */
/*   Updated: 2026/03/16 14:32:18 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void make_stack(t_stack **a, char **argv, bool fake)
{
	long num;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (syntax_fail(argv[i]))
			fail_free(a, argv, fake);
		num = ft_atol(*argv);
		if (num  > INT_MAX || num < INT_MIN)
			fail_free(a, argv, fake);
		if (rep_fail(*a, (int)num))
			fail_free(a, argv, fake);
		add_node(a, (int)num);
		i++;
	}
	if (fake)
		free_arr(a);
}

t_stack	*find_last(t_stack *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void add_node(t_stack **stack, int num)
{
	t_stack *node;
	t_stack *last_node;

	if (stack == NULL)
		return ;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = num;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

