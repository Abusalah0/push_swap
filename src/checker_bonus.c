/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:26:20 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/23 15:28:17 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	execute_op(char *op, t_item *a_stack, t_item *b_stack)
{
	if (strcmp(op, "ra\n"))
		ra(a_stack);
	else if (strcmp(op, "sa\n"))
		sa(a_stack);
	else if (strcmp(op, "pa\n"))
		pa(a_stack, b_stack);
	else if (strcmp(op, "rra\n"))
		rra(a_stack);
	else if (strcmp(op, "rb\n"))
		rb(a_stack);
	else if (strcmp(op, "sb\n"))
		sb(a_stack);
	else if (strcmp(op, "pb\n"))
		pb(a_stack, b_stack);
	else if (strcmp(op, "rrb\n"))
		rrb(a_stack);
	else if (strcmp(op, "rrr\n"))
		rrr(a_stack, b_stack);
	else if (strcmp(op, "rr\n"))
		rr(a_stack, b_stack);
	else if (strcmp(op, "ss\n"))
		ss(a_stack, b_stack);
	else
		return (false);
	return (true);
}
bool	exec_and_check_ops(char *op, t_item *a_stack, t_item *b_stack)
{
	if (!execute_op(op, a_stack, b_stack))
	{
		free(op);
		free_stack(a_stack);
		free_stack(b_stack);
		return (false);
	}
}

int	main(int argc, char **argv)
{
	char	*command;
	int		*num;
	t_item	*a_stack;
	t_item	*b_stack;

	if (argc < 2)
		return (1); // error
	a_stack = NULL;
	num = check_input(argc, argv);
	if (!num)
		return (1); // error
	fill_stack(&a_stack, num, argc - 1);
	// if sorted
	command = get_next_line(0);
	while (command)
	{
		if (!exec_and_check_ops(command, &a_stack, &b_stack))
		{
			free_stack(a_stack);
			free_stack(b_stack);
			free(command);
			return (1);
		}
		free(command);
		command = get_next_line(0);
	}
}
