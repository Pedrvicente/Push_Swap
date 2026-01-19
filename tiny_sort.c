/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-al <pedde-al@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:00:37 by pedde-al          #+#    #+#             */
/*   Updated: 2026/01/08 19:27:32 by pedde-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while(stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static	t_stack_node	*find_highest(t_stack_node *stack);

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*high_node;

	high_node = find_highest(*a);
	if (*a == high_node)
		ra(a, false);
	else if ((*a)->next == high_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

static	t_stack_node *find_highest(t_stack_node *stack)
{
	t_stack_node *high;

	if (stack == NULL)
		return (NULL);
	high = stack;
	while (stack)
	{
		if (stack->value > high->value)
				high = stack;
		stack = stack->next;
	}
	return (high);
}

t_stack_node *find_lowest(t_stack_node *stack)
{
	t_stack_node *low;

	if (stack == NULL)
		return (NULL);
	low = stack;
	while (stack)
	{
		if (stack->value < low->value)
				low = stack;
		stack = stack->next;
	}
	return (low);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while(stack_len(*a) > 3)
	{
		init_node(*a, *b);
		finish_rotation(a, find_lowest(*a), 'a');
		pb(b, a, false);
	}
}
