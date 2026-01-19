/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-al <pedde-al@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:32:41 by pedde-al          #+#    #+#             */
/*   Updated: 2026/01/15 12:23:05 by pedde-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **argv)
{
	int	i;

	i = 0;
	if (!argv || !(*argv))
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv - 1);
}

int	check_repetition(t_stack_node *a, int n)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	error_free(t_stack_node **a, char **argv, bool argc_2)
{
	free_stack(a);
	if (argc_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = (*stack);
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	(*stack) = NULL;
}

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
