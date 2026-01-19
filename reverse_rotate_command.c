/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-al <pedde-al@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:34:03 by pedde-al          #+#    #+#             */
/*   Updated: 2026/01/15 12:04:16 by pedde-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second_to_last;
	t_stack_node	*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	last_node = find_last_node(*stack);
	second_to_last = last_node->prev;
	
	first->prev = last_node;
	last_node->prev = NULL;
	last_node->next = first;
	second_to_last->next = NULL;
	(*stack) = last_node;
}

void	rra(t_stack_node **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}