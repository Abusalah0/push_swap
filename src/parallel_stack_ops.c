/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_stack_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:43:02 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/08 01:43:36 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_item **a_stack, t_item **b_stack, bool print)
{
	sa(a_stack, false);
	sb(b_stack, false);
	if (print)
	{
		write(1, "ss\n", 3);
	}
}

void	rr(t_item **a_stack, t_item **b_stack, bool print)
{
	ra(a_stack, false);
	rb(b_stack, false);
	if (print)
	{
		write(1, "rr\n", 3);
	}
}

void	rrr(t_item **a_stack, t_item **b_stack, bool print)
{
	rra(a_stack, false);
	rrb(b_stack, false);
	if (print)
	{
		write(1, "rrr\n", 4);
	}
}

void	rotate(t_item **a_stack, t_item **b_stack, t_item *cheapest)
{
	while (*b_stack != cheapest->target && *a_stack != cheapest)
	{
		rr(a_stack, b_stack, true);
	}
	update_node_index(*a_stack);
	update_node_index(*b_stack);
}

void	rrotate(t_item **a, t_item **b, t_item *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, true);
	update_node_index(*a);
	update_node_index(*b);
}
