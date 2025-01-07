/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_stack_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:43:02 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/07 14:36:05 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_item **a_stack, t_item **b_stack, bool print)
{
	sa(a_stack, false);
	sb(b_stack, false);
	if (print)
		printf("ss\n");
}
void	rr(t_item **a_stack, t_item **b_stack, bool print)
{
	ra(a_stack, false);
	rb(b_stack, false);
	if (print)
		printf("rr\n");
}

void	rrr(t_item **a_stack, t_item **b_stack, bool print)
{
	rra(a_stack, false);
	rrb(b_stack, false);
	if (print)
		printf("rrr\n");
}

void	rotate_both(t_item **a_stack, t_item **b_stack, t_item *cheapest)
{
	while (*b_stack != cheapest->target && *a_stack != cheapest)
	{
		rr(a_stack, b_stack, true);
	}
	current_index(*a_stack);
	current_index(*b_stack);
}

void	rev_rotate_both(t_item **a, t_item **b, t_item *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, true);
	current_index(*a);
	current_index(*b);
}
