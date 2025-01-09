/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers_for_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:32:18 by abdsalah          #+#    #+#             */
/*   Updated: 2025/01/09 04:03:07 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_b_to_a(t_item **a_stack, t_item **b_stack)
{
	set_cheapest_on_top_a(a_stack, (*b_stack)->target);
	pa(a_stack, b_stack, true);
}

void	update_nodes_b(t_item *a_stack, t_item *b_stack)
{
	update_node_index(b_stack);
	update_node_index(a_stack);
	set_target_node_b(a_stack, b_stack);
}

static void	target_helper(t_item *curser, t_item **target, t_item *b_stack,
		long *closest_match)
{
	if (curser->val > b_stack->val)
	{
		if (LONG_MIN == *closest_match || curser->val < *closest_match)
		{
			*closest_match = curser->val;
			*target = curser;
		}
	}
}

void	set_target_node_b(t_item *a_stack, t_item *b_stack)
{
	t_item	*curser;
	t_item	*target;
	long	closest_match;

	while (b_stack)
	{
		closest_match = LONG_MIN;
		curser = a_stack;
		while (curser)
		{
			target_helper(curser, &target, b_stack, &closest_match);
			curser = curser->next;
		}
		if (closest_match == LONG_MIN)
			b_stack->target = get_min(a_stack);
		else
			b_stack->target = target;
		b_stack = b_stack->next;
	}
}
