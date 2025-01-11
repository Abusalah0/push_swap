/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:38:52 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/11 13:29:00 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_execute_op(char *op, t_item **a_stack, t_item **b_stack)
{
	if (!ft_strcmp(op, "ra\n"))
		ft_ra(a_stack, false);
	else if (!ft_strcmp(op, "sa\n"))
		ft_sa(a_stack, false);
	else if (!ft_strcmp(op, "pa\n"))
		ft_pa(a_stack, b_stack, false);
	else if (!ft_strcmp(op, "rra\n"))
		ft_rra(a_stack, false);
	else if (!ft_strcmp(op, "rb\n"))
		ft_rb(b_stack, false);
	else if (!ft_strcmp(op, "sb\n"))
		ft_sb(b_stack, false);
	else if (!ft_strcmp(op, "pb\n"))
		ft_pb(a_stack, b_stack, false);
	else if (!ft_strcmp(op, "rrb\n"))
		ft_rrb(b_stack, false);
	else if (!ft_strcmp(op, "rrr\n"))
		ft_rrr(a_stack, b_stack, false);
	else if (!ft_strcmp(op, "rr\n"))
		ft_rr(a_stack, b_stack, false);
	else if (!ft_strcmp(op, "ss\n"))
		ft_ss(a_stack, b_stack, false);
	else
		return (false);
	return (true);
}

void	ft_exec_and_check_ops(t_item **a_stack, t_item **b_stack)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		if (!ft_execute_op(command, a_stack, b_stack))
		{
			free(command);
			ft_free_stack(*a_stack);
			ft_free_stack(*b_stack);
			ft_error_exit();
		}
		free(command);
		command = get_next_line(0);
	}
}

void	ft_final_check(t_item *a_stack, t_item *b_stack)
{
	if (ft_is_sorted(a_stack) && b_stack == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	int		*num;
	t_item	*a_stack;
	t_item	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (argc < 2)
		return (1);
	num = ft_check_input(argc, argv);
	if (!num)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_fill_stack(&a_stack, num, argc - 1);
	free(num);
	ft_exec_and_check_ops(&a_stack, &b_stack);
	ft_final_check(a_stack, b_stack);
	ft_free_stack(a_stack);
	ft_free_stack(b_stack);
	return (0);
}
